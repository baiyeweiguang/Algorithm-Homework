#include "../include/problem1.hpp"

#include <fmt/core.h>
#include <iostream>

namespace algo {
auto Scheduler::operator()(const int num) const -> Result {
  if (num % 2 != 0) {
    return {};
  }
  Result table(num, std::vector<int>(num - 1, 0));
  schedule(table, 1, num);
  return table;
}
auto Scheduler::schedule(Result &table, const int m, const int n) -> void {
  if (m + 1 == n) {
    table[m - 1][0] = n;
    table[n - 1][0] = m;
    return;
  }
  int width = n - m;
  int height = n - m + 1;
  (void)height;

  // 递归划分
  int mid = (m + n) / 2;
  schedule(table, m, mid);
  schedule(table, mid + 1, n);

  // 合并
   
  // 右下角=左上角
  int offset_x = width / 2 + 1;
  int offset_y = height / 2;
  for (int i = m + offset_x; i <= n; i++) {
    for (int j = width - offset_y + 1; j <= width + 1; j++) {
      table[i - 1][j - 1] = table[i - offset_x - 1][j - offset_y - 1];
    }
  }

  // 右上角=左下角
  for (int i = m; i < m + offset_x; i++) {
    for (int j = width - offset_y + 1; j <= width + 1; j++) {
      table[i - 1][j - 1] = table[i + offset_x - 1][j - offset_y - 1];
    }
  }

  // 中间一列=中间左边一列的倒序
  for (int i = 0; i < height; i++) {
    table[i + m - 1][offset_y - 1] = table[n - i - 1][offset_y - 2];
  } 
}

} // namespace algo