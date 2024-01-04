#include <chrono>
#include <iostream>
#include <set>
#include <thread>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "include/problem1.hpp"

TEST(Problem1Test, Test1) {
  auto config = YAML::LoadFile("../params.yaml");
  auto m = config["problem1"]["m"].as<int>();

  auto scheduler = algo::Scheduler();
  auto result = scheduler(m);

  for (int i = 0; i < m; i++) {
    std::set<int> s;
    for (int j = 0; j < m - 1; j++) {
      s.insert(result[i][j]);
    }
    for (int j = 1; j <= m - 1; j++) {
      if (j == i + 1) {
        continue;
      }
      ASSERT_EQ(s.count(j), 1);
    }
  }

  for (const auto & row : result) {
    for (const auto & col : row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }
}
