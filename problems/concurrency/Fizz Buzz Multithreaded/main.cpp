#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>

class FizzBuzz {
private:
  int n;
  int cur_num;
  bool is_end;
  mutable std::mutex m;
  mutable std::condition_variable cv;

public:
  FizzBuzz(int n) {
    this->n = n;
    this->cur_num = 1;
    this->is_end = false;
  }

  template <typename Func, typename ... Args>
  void Print(Func func, Args&& ... args) {
    if (cur_num <= n) {
      func(std::forward<Args>(args)...);
      cur_num++;
    }
    else {
      is_end = true;
    }
    cv.notify_all();
  }

  void fizz(std::function<void()> printFizz) {
    while (true) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this]() { return (cur_num % 3 == 0 && cur_num % 5 != 0) || is_end; });
      if (is_end) {
        break;
      }
      else {
        Print(printFizz);
      }
    }
  }

  void buzz(std::function<void()> printBuzz) {
    while (true) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this]() { return (cur_num % 3 != 0 && cur_num % 5 == 0) || is_end; });
      if (is_end) {
        break;
      }
      else {
        Print(printBuzz);
      }
    }
  }

  void fizzbuzz(std::function<void()> printFizzBuzz) {
    while (true) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this]() { return (cur_num % 3 == 0 && cur_num % 5 == 0) || is_end; });
      if (is_end) {
        break;
      }
      else {
        Print(printFizzBuzz);
      }
    }
  }

  void number(std::function<void(int)> printNumber) {
    while (true) {
      std::unique_lock<std::mutex> lock(m);
      cv.wait(lock, [this]() { return (cur_num % 3 != 0 && cur_num % 5 != 0) || is_end; });
      if (is_end) {
        break;
      }
      else {
        Print(printNumber, cur_num);
      }
    }
  }
};

void thread_fizz(FizzBuzz& fizz_buzz) {
  fizz_buzz.fizz([]() { std::cout << "fizz "; });
}

void thread_buzz(FizzBuzz& fizz_buzz) {
  fizz_buzz.buzz([]() { std::cout << "buzz "; });
}

void thread_fizzbuzz(FizzBuzz& fizz_buzz) {
  fizz_buzz.fizzbuzz([]() { std::cout << "fizzbuzz "; });
}

void thread_number(FizzBuzz& fizz_buzz) {
  fizz_buzz.number([](int x) { std::cout << x << ' '; });
}

int main() {
  int n = 0;
  std::cin >> n;

  FizzBuzz fizz_buzz(n);

  auto fizz = std::async(std::launch::async, &thread_fizz, std::ref(fizz_buzz));
  auto buzz = std::async(std::launch::async, &thread_buzz, std::ref(fizz_buzz));
  auto fizzbuzz = std::async(std::launch::async, &thread_fizzbuzz, std::ref(fizz_buzz));
  auto number = std::async(std::launch::async, &thread_number, std::ref(fizz_buzz));

  fizz.get();
  buzz.get();
  fizzbuzz.get();
  number.get();

  std::cout << std::endl;
  return 0;
}
