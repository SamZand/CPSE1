#include <fstream>
#include <iostream>

#include "compressor.hpp"
#include "decompressor.hpp"

int main(void) {
  lz_compressor<4096> compressor;

  std::ifstream f1;
  f1.open("wilhelmus.txt");
  if (!f1.is_open()) {
    std::cerr << "input file not opened";
    return -1;
  }

  // Create asm file
  std::ofstream f2;
  f2.open("compressed.asm");
  if (!f2.is_open()) {
    std::cerr << "output file not opened";
    return -1;
  }

  f2 << ".cpu cortex-m0\n"
     << ".data\n"
     << ".align 2\n"
     << ".global compressed_data\n"
     << "compressed_data:\n"
     << ".asciz \"";

  compressor.compress(
      [&f1]() -> int {
        auto c = f1.get();
        return f1.eof() ? '\0' : c;
      },
      [&f2](char c) { f2.put(c); });

  f1.close();
  f2.close();
}