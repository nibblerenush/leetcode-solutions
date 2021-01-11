#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <sstream>
#include <vector>

class DiningPhilosophers {
public:
  const std::vector<std::pair<int, int>> philosopher_forks = {
    {0, 4},
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3}
  };
  
  std::vector<bool> forks_picked;
  mutable std::vector<std::condition_variable> forks_cv;
  mutable std::vector<std::mutex> forks_m;
  
  DiningPhilosophers() : forks_picked(5, false), forks_cv(5), forks_m(5)
  {}
  
  void wantsToEat(int philosopher,
    std::function<void()> pickLeftFork,
    std::function<void()> pickRightFork,
    std::function<void()> eat,
    std::function<void()> putLeftFork,
    std::function<void()> putRightFork)
  {
    const auto& forks = philosopher_forks[philosopher];
    pickFork(forks.first, pickLeftFork);
    pickFork(forks.second, pickRightFork);
    eat();
    putFork(forks.first, putLeftFork);
    putFork(forks.second, putRightFork);
  }
  
  void pickFork(int fork_number, std::function<void()> pickForkMove) {
    std::unique_lock<std::mutex> lock(forks_m[fork_number]);
    forks_cv[fork_number].wait(lock, [this, fork_number]() { return !forks_picked[fork_number]; });
    forks_picked[fork_number] = true;
    pickForkMove();
  }
  
  void putFork(int fork_number, std::function<void()> putForkMove) {
    std::unique_lock<std::mutex> lock(forks_m[fork_number]);
    forks_picked[fork_number] = false;
    putForkMove();
    forks_cv[fork_number].notify_one();
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

template <int N>
void run_thread(std::vector<std::future<void>>& threads, DiningPhilosophers& dp, int n) {
  threads.push_back(std::async(std::launch::async, &philosopher_thread<N - 1>, std::ref(dp), n));
  run_thread<N - 1>(threads, dp, n);
}

template <>
void run_thread<0>(std::vector<std::future<void>>&, DiningPhilosophers&, int) {}

int main() {
  int n = 0;
  std::cin >> n;
  
  DiningPhilosophers dp;
  std::vector<std::future<void>> threads;
  run_thread<5>(threads, dp, n);

  for (auto& thread : threads) {
    thread.get();
  }
  std::cout << std::endl;
  return 0;
}
