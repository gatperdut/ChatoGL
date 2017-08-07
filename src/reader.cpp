// Standard
#include <fstream>
#include <sstream>

// Custom
#include "reader.h"

std::string read(std::string filePath, bool* success) {
  std::string text;

  std::stringstream fileStream;
  std::ifstream file(filePath.c_str());
  if (!file) {
    std::cerr << "ERROR::READER::MISSING " << filePath << std::endl;
    *success = false;
    return NULL;
  }
  fileStream << file.rdbuf();
  file.close();
  text = fileStream.str();

  *success = true;
  return text;
}
