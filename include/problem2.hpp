#ifndef PROBLEM_2_HPP_
#define PROBLEM_2_HPP_

#include <vector>

namespace algo {

class TaskScheduler {
public:
  TaskScheduler() = default;
  auto schedule(const std::vector<int> &machine_a,
                const std::vector<int> &machine_b) -> int;
  auto trackSolution() const -> std::vector<std::pair<int, int>>;

private:
  std::vector<std::vector<int>> dp_;
  struct Memo {
    bool use_a;
    int prev_j;
  };
  std::vector<std::vector<Memo>> track_;
  int last_j_;
};

} // namespace algo
#endif // PROBLEM_2_HPP_