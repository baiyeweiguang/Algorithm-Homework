#include <fmt/core.h>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "include/problem3.hpp"

TEST(Problem3Test, Test3) {
  auto config = YAML::LoadFile("../params.yaml");
  auto n = config["problem3"]["n"].as<std::string>();
  auto k = config["problem3"]["k"].as<int>();

  auto min_number = algo::MinNumber();
  auto result = min_number(n, k);


  fmt::print("最小的数为：{}\n", result);
}
