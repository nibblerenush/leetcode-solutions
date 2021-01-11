#include <functional>
#include <future>
#include <iostream>

class Foo {
public:
  Foo() {}
  
  void first(std::function<void()> printFirst) {
    printFirst();
    count++;
    cv1.notify_one();
  }

  void second(std::function<void()> printSecond) {
    std::unique_lock<std::mutex> guard(m);
    cv1.wait(guard, [this](){ return count == 2; });
    printSecond();
    count++;
    cv2.notify_one();
  }
  
  void third(std::function<void()> printThird) {
    std::unique_lock<std::mutex> guard(m);
    cv2.wait(guard, [this](){ return count == 3; });
    printThird();
  }
  
private:
  int count = 1;
  mutable std::mutex m;
  mutable std::condition_variable cv1;
  mutable std::condition_variable cv2;
};

void thread_first(Foo& foo) {
  foo.first([](){ std::cout << "first"; });
}

void thread_second(Foo& foo) {
  foo.second([](){ std::cout << "second"; });
}

void thread_third(Foo& foo) {
  foo.third([](){ std::cout << "thrid" << std::endl; });
}

int main() {
  Foo foo;
  std::future<void> future_first = std::async(&thread_first, std::ref(foo));
  std::future<void> future_second = std::async(&thread_second, std::ref(foo));
  std::future<void> future_third = std::async(&thread_third, std::ref(foo));
  return 0;
}
