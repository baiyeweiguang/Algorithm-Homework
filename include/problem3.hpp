#ifndef PROBLEM_3_HPP_
#define PROBLEM_3_HPP_

#include <string>

namespace algo {
class MinNumber {
public:
  MinNumber() = default;
  auto operator()(const std::string &a, int k) const -> std::string;
};
} // namespace algo
#endif // PROBLEM_3_HPP_