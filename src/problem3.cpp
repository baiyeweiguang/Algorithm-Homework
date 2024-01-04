#include "../include/problem3.hpp"

#include <string>

namespace algo {
auto MinNumber::operator()(const std::string &number, int k) const
    -> std::string {
  auto result = std::string("");

  for (char c : number) {
    // k > 0： 还要再删除
    // reuslt.back() > c:
    // 当前的c比result最后一个数小，替换掉result.back()能使结果更小
    while (k > 0 && !result.empty() && result.back() > c) {
      result.pop_back();
      --k;
    }
    if (c != '0' || !result.empty()) {
      result.push_back(c);
    }
  }
  // 如果k还大于0，说明还要删除，从后面删除
  while (k > 0 && !result.empty()) {
    result.pop_back();
    --k;
  }
  return result.empty() ? "0" : result;
}
} // namespace algo