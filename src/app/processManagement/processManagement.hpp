#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "task.hpp"
#include <memory>
#include <queue>

class ProcessManagement {
public:
  ProcessManagement();
  bool submit_to_queue(std::unique_ptr<Task> task);
  void execute_task();

private:
  std::queue<std::unique_ptr<Task>> task_queue;
};

#endif
