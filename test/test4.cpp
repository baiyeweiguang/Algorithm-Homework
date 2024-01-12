#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "../include/problem4.hpp"

TEST(Problem4Test, Test4) {
  auto config = YAML::LoadFile("../params.yaml");
  auto board = config["problem4"]["sudoko"].as<std::vector<std::vector<int>>>();

  auto sudoko = algo::Sudoko();
  if (sudoko.solve(board)) {
    fmt::print("解为：\n");
    auto result = sudoko.getSolvedBoard();
    for (const auto &row : result) {
      for (const auto &v : row) {
        fmt::print("{} ", v);
      }
      fmt::print("\n");
    }
  } else {
    fmt::print("无解\n");
  }
}