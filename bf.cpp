#include <iostream>
#include <fstream>

#include "bf.hpp"

BrainFuck::BrainFuck() : code_buf_{}, mem_{0}, data_ptr_{0} {
}

void BrainFuck::Load(const std::string path) {
  std::ifstream ifs{path, std::ios::binary | std::ios::in};
  if (!ifs.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  char data;
  while (ifs.get(data)) {
    // ignore all non-token characters
    if (kTokens.find(data) != std::string::npos) {
      code_buf_.push_back(static_cast<uint8_t>(data));
    }
  }
  std::cout << "Loaded file" << std::endl;
}

void BrainFuck::Run() {
  for (auto inst_ptr = code_buf_.begin(); inst_ptr != code_buf_.end(); ++inst_ptr) {
    switch (*inst_ptr) {
      case '>':
        ++data_ptr_;
        break;
      case '<':
        --data_ptr_;
        break;
      case '+':
        mem_[data_ptr_]++;
        break;
      case '-':
        mem_[data_ptr_]--;
        break;
      case '.':
        std::cout << mem_[data_ptr_];
        break;
      case ',':
        std::cin >> mem_[data_ptr_];
        break;
      case '[':
        // deal with nested structure
        {
          if (mem_[data_ptr_] == 0) {
            int depth = 1;
            while (depth >= 1) {
              ++inst_ptr;
              if (*inst_ptr == '[') {
                ++depth;
              } else if (*inst_ptr == ']') {
                --depth;
              }
            }
          }
        }
        break;
      case ']':
        // deal with nested structure
        {
          if (mem_[data_ptr_] != 0) {
            int depth = 1;
            while (depth >= 1) {
              --inst_ptr;
              if (*inst_ptr == ']') {
                ++depth;
              } else if (*inst_ptr == '[') {
                --depth;
              }
            }
          }
        }
        break;
      default:
        std::cerr << "Not implemented: " << *inst_ptr << std::endl;
        std::exit(EXIT_FAILURE);
    }
  }
}