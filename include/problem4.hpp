#ifndef PROBLEM_4_HPP_
#define PROBLEM_4_HPP_

#include <vector>

namespace algo {
class Sudoko {
public:
  using Result = std::vector<std::vector<int>>;

  Sudoko() = default;
  auto solve(std::vector<std::vector<int>> &board) -> bool;
  auto getSolvedBoard() const -> Result;

private:
  void dp(std::vector<std::vector<int>> &board, int row, int col);
  bool isValid(std::vector<std::vector<int>> &board, int row, int col, int num);

  Result solved_board_;
};

} // namespace algo
#endif // PROBLEM_4_HPP_