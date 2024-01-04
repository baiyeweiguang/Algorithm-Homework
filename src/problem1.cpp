#include "../include/problem1.hpp"

#include <iostream>
#include <fmt/core.h>

namespace algo {
auto Scheduler::operator()(const int m) const -> Result {
  if (m % 2 != 0) {
    return {};
  }
  Result table(m, std::vector<int>(m - 1, 0));
  schedule(table, m);
  return table;
}

auto Scheduler::schedule(Result &table, const int m) -> void {
  if (m == 2) {
    table[0][0] = 2;
    table[1][0] = 1;
    return;
  }

  // 递归划分m/2个选手的赛程表
  schedule(table, m / 2);

  // 以8个人为例
  // 2 4
  // 1 3
  // 4 2
  // 3 1
  // 可见左下角=左上角+m/2，右下角=左上角，右上角=左下角

  // 左下角
  int mid = m / 2;
  for (int i = mid; i < m; i++) {
    for (int j = 0; j < mid - 1; j++) {
      table[i][j] = table[i - mid][j] + mid;
    }
  }
  // 右下角
  for (int i = mid; i < m; i++) {
    for (int j = mid; j < m - 1; j++) {
      table[i][j] = table[i - mid][j - mid];
    }
  }
  // 右上角
  for (int i = 0; i < mid; i++) {
    for (int j = mid; j < m - 1; j++) {
      table[i][j] = table[i + mid][j - mid];
    }
  }
  // 中间一列
  for (int i = 0; i < m; i++) {
    table[i][mid - 1] = table[m-i-1][mid-2];
  }
}

} // namespace algo