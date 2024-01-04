#ifndef PROBLEM_1_HPP_
#define PROBLEM_1_HPP_

#include <vector>

namespace algo {

class Scheduler {
public:
  using Result = std::vector<std::vector<int>>;
  Scheduler() = default;
  auto operator()(const int m) const -> Result;

private:
  static auto schedule(Result &table, const int m) -> void;
};

} // namespace algo
#endif // PROBLEM_1_HPP_