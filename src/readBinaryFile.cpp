#ifndef _HELLO_TRIANGLE_READBINFILE
#define _HELLO_TRIANGLE_READBINFILE
#include <fstream>
#include <vector>
#include <stdexcept>
#include <thread>

struct Buffer {
  char * data;
  size_t size;
};

Buffer readBinaryFile(const std::string& filename) {
  std::ifstream file(filename, std::ios::ate | std::ios::binary);

  if (!file.is_open()) {
    throw std::runtime_error("failed to open file");
  }

  size_t fileSize {(size_t) file.tellg()};
  char * buffer {new char[fileSize]};

  file.seekg(0);
  file.read(buffer, fileSize);
  file.close();

  return {buffer, fileSize};
}
#endif