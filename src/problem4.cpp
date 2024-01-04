#include "../include/problem4.hpp"

#include <algorithm>
#include <iostream>

#include <fmt/color.h>
#include <fmt/core.h>

namespace algo {
auto Sudoko::solve(std::vector<std::vector<int>> &board) -> bool {
  dp(board, 0, 0);
  return !solved_board_.empty();
}

auto Sudoko::dp(std::vector<std::vector<int>> &board, int row, int col)
    -> void {
  if (row == 9) {
    solved_board_ = board;
    return;
  }

  // 原来有数字，直接跳过
  if (board[row][col] != 0) {
    if (col == 8) {
      dp(board, row + 1, 0);
    } else {
      dp(board, row, col + 1);
    }
    return;
  }

  for (int i = 1; i <= 9; i++) {
    if (isValid(board, row, col, i)) {
      board[row][col] = i;
      if (col == 8) {
        dp(board, row + 1, 0);
      } else {
        dp(board, row, col + 1);
      }
      board[row][col] = 0;
    }
  }
}

auto Sudoko::isValid(std::vector<std::vector<int>> &board, int row, int col,
                     int num) -> bool {
  // 检查行
  for (int i = 0; i < 9; ++i) {
    if (i == col)
      continue;
    if (board[row][i] == num) {
      return false;
    }
  }
  // 检查列
  for (int i = 0; i < 9; ++i) {
    if (i == row)
      continue;
    if (board[i][col] == num) {
      return false;
    }
  }
  // 检查3*3的小方格
  int start_row = row / 3 * 3;
  int start_col = col / 3 * 3;
  for (int i = start_row; i < start_row + 3; ++i) {
    for (int j = start_col; j < start_col + 3; ++j) {
      if (i == row && j == col)
        continue;
      if (board[i][j] == num) {
        return false;
      }
    }
  }
  return true;
}

auto Sudoko::getSolvedBoard() const -> Result { return solved_board_; }

} // namespace algo