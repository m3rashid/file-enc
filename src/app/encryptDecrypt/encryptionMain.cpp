#include "encryption.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: bin <task_data>" << std::endl;
    return 1;
  }

  execute_encryption(argv[1]);
  return 0;
}
