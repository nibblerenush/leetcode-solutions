#include <iostream>
#include <functional>
#include <future>

class H2O {
public:
  H2O() {}
  
  void hydrogen(std::function<void()> releaseHydrogen) {
    std::unique_lock<std::mutex> lock(m);
    cv_h.wait(lock, [this](){ return hydrogen_counter <= 1 && oxygen_counter <= 1; });

    ++hydrogen_counter;
    if (hydrogen_counter == 2 && oxygen_counter == 1) {
      hydrogen_counter = 0;
      oxygen_counter = 0;
      cv_o.notify_all();
      cv_h.notify_all();
    }

    releaseHydrogen();
  }
  
  void oxygen(std::function<void()> releaseOxygen) {
    std::unique_lock<std::mutex> lock(m);
    cv_o.wait(lock, [this](){ return hydrogen_counter <= 2 && oxygen_counter == 0; });

    ++oxygen_counter;
    if (hydrogen_counter == 2 && oxygen_counter == 1) {
      hydrogen_counter = 0;
      oxygen_counter = 0;
      cv_o.notify_all();
      cv_h.notify_all();
    }

    releaseOxygen();
  }

private:
  mutable std::mutex m;
  mutable std::condition_variable cv_o;
  mutable std::condition_variable cv_h;
  int hydrogen_counter = 0;
  int oxygen_counter = 0;
};

void hydrogen_thread(H2O& h2o, int n) {
  for (int i = 0; i < 2 * n; ++i) {
    h2o.hydrogen([](){ std::cerr << 'H'; });
  }
}

void oxygen_thread(H2O& h2o, int n) {
  for (int i = 0; i < n; ++i) {
    h2o.oxygen([](){ std::cerr << 'O'; });
  }
}

int main() {
  int n = 0;
  std::cin >> n;

  H2O h2o;
  std::future<void> future_hydrogen = std::async(&hydrogen_thread, std::ref(h2o), n);
  std::future<void> future_oxygen = std::async(&oxygen_thread, std::ref(h2o), n);

  future_hydrogen.get();
  future_oxygen.get();

  std::cout << std::endl;
  return 0;
}
