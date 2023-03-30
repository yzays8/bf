#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <array>

constexpr int kMemSize = 1 << 16;

const std::string kTokens = R"(<>>+-.,[])";

class BrainFuck {
 public:
  BrainFuck();
  void Load(const std::string path);
  void Run();

 private:
  std::vector<uint8_t> code_buf_;
  std::array<uint8_t, kMemSize> mem_;
  int data_ptr_;
};