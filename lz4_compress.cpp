// Own headers
#include "lz4_stream.h"

// Standard headers
#include <algorithm>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " inputfile outputfile" << std::endl;
    return 1;
  }
  std::ifstream in_file(argv[1]);
  std::ofstream out_file(argv[2]);

  lz4_stream::ostream lz4_stream(out_file);

  std::copy(std::istreambuf_iterator<char>(in_file),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(lz4_stream));

  return 0;
}
