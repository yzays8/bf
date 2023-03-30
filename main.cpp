#include <iostream>
#include <memory>

#include "bf.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Arguments error" << std::endl;
    return 1;
  }

  auto bf = std::make_unique<Brainfuck>();
  bf->Load(argv[1]);
  bf->Run();
}