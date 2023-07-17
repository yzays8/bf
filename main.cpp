#include <iostream>
#include <memory>

#include "bf.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Arguments error" << std::endl;
    return 1;
  }

  auto bf = std::make_unique<Brainfuck>();
  if (!bf->Load(argv[1])) {
    return 1;
  }
  bf->Run();
}