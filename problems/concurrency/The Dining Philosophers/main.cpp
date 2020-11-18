#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <sstream>
#include <vector>

class DiningPhilosophers {
public:
  std::vector<std::pair<int, int>> philosopher_forks = {
    {0, 4},
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3}
  };
  
  std::vector<bool> forks_picked;
  mutable std::vector<std::condition_variable> forks_cv;
  mutable std::mutex m;
  
  DiningPhilosophers() : forks_picked(5, false), forks_cv(5)
  {}
  
  void wantsToEat(int philosopher,
    std::function<void()> pickLeftFork,
    std::function<void()> pickRightFork,
    std::function<void()> eat,
    std::function<void()> putLeftFork,
    std::function<void()> putRightFork)
  {
    const auto& forks = philosopher_forks[philosopher];
    {
      std::unique_lock<std::mutex> lock(m);
      forks_cv[forks.first].wait(lock, [this, &forks]() { return !forks_picked[forks.first]; });
      forks_picked[forks.first] = true;
      pickLeftFork();
    }

    {
      std::unique_lock<std::mutex> lock(m);
      forks_cv[forks.second].wait(lock, [this, &forks]() { return !forks_picked[forks.second]; });
      forks_picked[forks.second] = true;
      pickRightFork();
    }

    eat();

    {
      std::unique_lock<std::mutex> lock(m);
      forks_picked[forks.first] = false;
      putLeftFork();
      forks_cv[forks.first].notify_one();
    }

    {
      std::unique_lock<std::mutex> lock(m);
      forks_picked[forks.second] = false;
      putRightFork();
      forks_cv[forks.second].notify_one();
    }
  }
};

static const char pickLeftFork[] = "pickLeftFork";
static const char pickRightFork[] = "pickRightFork";
static const char eat[] = "eat";
static const char putLeftFork[] = "putLeftFork";
static const char putRightFork[] = "putRightFork";

template <int philosopher, const char* move_name>
void move() {
  std::ostringstream oss;
  oss << "philosopher " << philosopher << ' ' << move_name << '\n';
  std::cout << oss.str();
}

template <int philosopher>
void philosopher_thread(DiningPhilosophers& dining_philosophers, int n) {
  for (int i = 0; i < n; ++i) {
    dining_philosophers.wantsToEat(philosopher,
      move<philosopher, pickLeftFork>,
      move<philosopher, pickRightFork>,
      move<philosopher, eat>,
      move<philosopher, putLeftFork>,
      move<philosopher, putRightFork>);
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  
  DiningPhilosophers dp;
  auto philosopher0 = std::async(std::launch::async, &philosopher_thread<0>, std::ref(dp), n);
  auto philosopher1 = std::async(std::launch::async, &philosopher_thread<1>, std::ref(dp), n);
  auto philosopher2 = std::async(std::launch::async, &philosopher_thread<2>, std::ref(dp), n);
  auto philosopher3 = std::async(std::launch::async, &philosopher_thread<3>, std::ref(dp), n);
  auto philosopher4 = std::async(std::launch::async, &philosopher_thread<4>, std::ref(dp), n);
  
  philosopher0.get();
  philosopher1.get();
  philosopher2.get();
  philosopher3.get();
  philosopher4.get();

  std::cout << std::endl;
  return 0;
}
