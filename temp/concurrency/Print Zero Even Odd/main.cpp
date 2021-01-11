#include <functional>
#include <future>
#include <iostream>

class ZeroEvenOdd {
private:
  enum class FunctionType {
    ZERO,
    EVEN,
    ODD
  };
  
public:
  ZeroEvenOdd(int n) {
    this->n = n;
    this->type = FunctionType::ZERO;
  }
  
  void zero(std::function<void(int)> printNumber) {
    for (int i = 1; i <= n; ++i) {
      std::unique_lock<std::mutex> lock(m);
      cv_zero.wait(lock, [this]() { return type == FunctionType::ZERO; });
      
      printNumber(0);
      if (i % 2 == 0) {
        type = FunctionType::EVEN;
        cv_even.notify_one();
      }
      else {
        type = FunctionType::ODD;
        cv_odd.notify_one();
      }
    }
  }
  
  void even(std::function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      std::unique_lock<std::mutex> lock(m);
      cv_even.wait(lock, [this](){ return type == FunctionType::EVEN; });
      
      printNumber(i);
      type = FunctionType::ZERO;
      cv_zero.notify_one();
    }
  }
  
  void odd(std::function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      std::unique_lock<std::mutex> lock(m);
      cv_odd.wait(lock, [this](){ return type == FunctionType::ODD; });
      
      printNumber(i);
      type = FunctionType::ZERO;
      cv_zero.notify_one();
    }
  }

private:
  int n;
  mutable std::mutex m;
  mutable std::condition_variable cv_zero;
  mutable std::condition_variable cv_even;
  mutable std::condition_variable cv_odd;
  FunctionType type;
};

void thread_zero(ZeroEvenOdd& zeroEvenOdd) {
  zeroEvenOdd.zero([](int x){ std::cout << x; });
}

void thread_even(ZeroEvenOdd& zeroEvenOdd) {
  zeroEvenOdd.even([](int x){ std::cout << x; });
}

void thread_odd(ZeroEvenOdd& zeroEvenOdd) {
  zeroEvenOdd.odd([](int x){ std::cout << x; });
}

int main() {
  int n;
  std::cin >> n;
  ZeroEvenOdd zeroEvenOdd(n);
  
  std::future<void> zero = std::async(&thread_zero, std::ref(zeroEvenOdd));
  std::future<void> even = std::async(&thread_even, std::ref(zeroEvenOdd));
  std::future<void> odd = std::async(&thread_odd, std::ref(zeroEvenOdd));
  
  zero.get();
  even.get();
  odd.get();
  
  std::cout << std::endl;
  return 0;
}
