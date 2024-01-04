#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "include/problem2.hpp"

TEST(Problem1Test, Test2) {
  auto config = YAML::LoadFile("../params.yaml");
  auto machine1 = config["problem2"]["machine1"].as<std::vector<float>>();
  auto machine2 = config["problem2"]["machine2"].as<std::vector<float>>();

  ASSERT_EQ(machine1.size(), machine2.size());

  auto meachine_1_int = std::vector<int>(machine1.size());
  auto meachine_2_int = std::vector<int>(machine2.size());
  for (int i = 0; i < machine1.size(); i++) {
    meachine_1_int[i] = static_cast<int>(machine1[i]);
    meachine_2_int[i] = static_cast<int>(machine2[i]);
  }

  auto scheduler = algo::TaskScheduler();
  auto result = scheduler.schedule(meachine_1_int, meachine_2_int);
  auto track = scheduler.trackSolution();

  std::vector<int> order1, order2;
  for (const auto &pair : track) {
    if (pair.first == 1) {
      order1.push_back(pair.second);
    } else {
      order2.push_back(pair.second);
    }
  }

  fmt::print("第一台机器的顺序为：");
  for (const auto &i : order1) {
    fmt::print("{} ", i);
  }
  fmt::print("\n第二台机器的顺序为：");
  for (const auto &i : order2) {
    fmt::print("{} ", i);
  }
  fmt::print("\n总时间为：{}\n", result);
}