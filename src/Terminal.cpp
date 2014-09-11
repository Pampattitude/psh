#include "Terminal.hpp"

std::string Terminal::endl = "\n";

Terminal::Terminal()
  : input_(&std::cin), output_(&std::cout)
{
}
