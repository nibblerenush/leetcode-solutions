#include <functional>
#include <future>
#include <iostream>

class FooBar {
private:
  enum class FunctionType {
    FOO,
    BAR
  };

public:
  FooBar(int n) {
    this->n = n;
    this->type = FunctionType::FOO;
  }

  void foo(std::function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this](){ return type == FunctionType::FOO; });
      printFoo();
      type = FunctionType::BAR;
      cv.notify_one();
    }
  }

  void bar(std::function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this](){ return type == FunctionType::BAR; });
      printBar();
      type = FunctionType::FOO;
      cv.notify_one();
    }
  }

private:
  int n;
  mutable std::mutex m;
  mutable std::condition_variable cv;
  FunctionType type;
};

void thread_foo(FooBar& foobar) {
  foobar.foo([](){ std::cout << "foo"; });
}

void thread_bar(FooBar& foobar) {
  foobar.bar([](){ std::cout << "bar"; });
}

int main() {
  int n;
  std::cin >> n;
  FooBar foobar(n);

  std::future<void> foo = std::async(&thread_foo, std::ref(foobar));
  std::future<void> bar = std::async(&thread_bar, std::ref(foobar));

  foo.get();
  bar.get();

  std::cout << std::endl;
  return 0;
}
