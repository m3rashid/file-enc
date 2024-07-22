#include "encryption.hpp"
#include "../fileHandling/read_env.cpp"
#include "../processes/task.hpp"

int execute_encryption(const std::string &task_data) {
  Task task = Task::fromString(task_data);
  ReadEnv env;
  std::string envKey = env.getenv();
  int key = std::stoi(envKey);
  if (task.action == Action::ENCRYPT) {
    char ch;
    while (task.f_stream.get(ch)) {
      ch = (ch + key) % 256;
      task.f_stream.seekp(-1, std::ios::cur);
      task.f_stream.put(ch);
    }
    task.f_stream.close();
  } else {
    char ch;
    while (task.f_stream.get(ch)) {
      ch = (ch - key + 256) % 256;
      task.f_stream.seekp(-1, std::ios::cur);
      task.f_stream.put(ch);
    }
    task.f_stream.close();
  }

  return 0;
}
