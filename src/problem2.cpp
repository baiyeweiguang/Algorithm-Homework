#include "../include/problem2.hpp"

#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <limits>
#include <numeric>
#include <tuple>
#include <vector>

namespace algo {

// constexpr auto FLT_MAX = std::numeric_limits<float>::max();
constexpr auto INT_MAX = std::numeric_limits<int>::max();

auto TaskScheduler::schedule(const std::vector<int> &a,
                             const std::vector<int> &b) -> int {
  using std::max;
  using std::min;
  using std::vector;

  int n = a.size();
  int suma = std::accumulate(a.begin(), a.end(), 0);
  int sumb = std::accumulate(b.begin(), b.end(), 0);

  // dp_[i][j]: 处理第i个零件，机器a总共用时为j时，机器b的最小时间
  dp_ = vector<vector<int>>(n + 1, vector<int>(max(suma, sumb) + 1, INT_MAX));
  // track_[i][j]: i,j状态下，{上一个状态的机器a是否使用过，上一个状态的j}
  track_ = std::vector<std::vector<Memo>>(
      n + 1,
      std::vector<Memo>(max(suma, sumb) + 1, {.use_a = false, .prev_j = 0}));

  for (int j = 0; j <= max(suma, sumb); j++) {
    dp_[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    dp_[i][0] = dp_[i - 1][0] + a[i - 1];
  }

  suma = 0;
  for (int i = 1; i <= n; i++) {
    suma += a[i - 1];
    for (int j = 1; j <= suma; j++) {
      dp_[i][j] = dp_[i][j - 1];
      track_[i][j] = {track_[i][j - 1].use_a, j - 1};

      if (dp_[i - 1][j] != INT_MAX) {
        dp_[i][j] = dp_[i - 1][j] + b[i - 1];
        track_[i][j] = {false, j};
      }

      if (dp_[i - 1][j - a[i - 1]] != INT_MAX && j >= a[i - 1]) {
        dp_[i][j] = min(dp_[i][j], dp_[i - 1][j - a[i - 1]]);
        track_[i][j] = {true, j - a[i - 1]};
      }
    }
  }

  int ans = INT_MAX;
  for (int j = 0; j <= suma; j++) {
    // 对部分j，可能dp_[n][j]没有更新过，此时dp_[n][j]为INT_MAX
    auto temp = max(dp_[n][j], j);
    if (temp < ans) {
      last_j_ = j;
      ans = temp;
    }
  }

  return ans;
}

auto TaskScheduler::trackSolution() const -> std::vector<std::pair<int, int>> {
  using std::pair;
  using std::vector;

  vector<pair<int, int>> solution;
  int n = dp_.size() - 1;
  int i = n;
  int j = last_j_;

  while (i > 0) {
    const auto &[use_a, prev_j] = track_[i][j];
    if (use_a) {
      solution.emplace_back(1, i); // Machine 1
    } else {
      solution.emplace_back(2, i); // Machine 2
    }
    i--;
    j = prev_j;
  }
  reverse(solution.begin(), solution.end());
  return solution;
}

} // namespace algo