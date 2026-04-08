#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Correct usage: " << argv[0] << " <argv1> <argv2>\n";
    return EXIT_FAILURE;
  }
  try {
    fs::path source = argv[1];
    std::string output = argv[2];
    // check if the file exist to system
    if (!fs::exists(source)) {
      throw std::runtime_error("Source file doesn't exist: " + source.string());
    }
    // check the extension
    if (source.extension() != ".cpp") {
      throw std::runtime_error("This: " + source.string() + " is not a cpp file!");
    }

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return EXIT_FAILURE;
  }

  std::string command = "g++ ";
  command.append(argv[1]);
  command.append(" -o ");
  command.append(argv[2]);

  std::cout << argv[1];
  std::system(command.c_str());
}