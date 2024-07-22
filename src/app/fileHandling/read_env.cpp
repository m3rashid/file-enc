#include "IO.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

class ReadEnv {
public:
  std::string getenv() {
    std::string envpath = ".env";
    IO io(envpath);
    std::fstream f_stream = io.get_file_stream();
    std::stringstream buffer;
    buffer << f_stream.rdbuf();
    std::string content = buffer.str();
    return content;
  }
};
