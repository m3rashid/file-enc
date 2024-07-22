#include "./src/app/processManagement/processManagement.hpp"
#include "./src/app/processManagement/task.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  std::string directory;
  std::string action;

  std::cout << "Enter the directory path: ";
  std::getline(std::cin, directory);

  std::cout << "Enter the action (ENCRYPT/DECRYPT): ";
  std::getline(std::cin, action);

  try {
    if (fs::exists(directory) && fs::is_directory(directory)) {
      ProcessManagement process_mgmt;
      for (const auto &entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
          std::string file_path = entry.path().string();
          IO io(file_path);
          std::fstream f_stream = std::move(io.get_file_stream());

          if (f_stream.is_open()) {
            Action ac = action == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT;
            auto task =
                std::make_unique<Task>(std::move(f_stream), ac, file_path);
            process_mgmt.submit_to_queue(std::move(task));
          } else {
            std::cout << "Unable to open file: " << file_path << std::endl;
          }
        }
      }

      process_mgmt.execute_task();
    } else {
      std::cout << "Invalid directory path: " << std::endl;
    }
  } catch (const fs::filesystem_error &ex) {
    std::cout << "File system error: " << ex.what() << std::endl;
  }

  return 0;
}
