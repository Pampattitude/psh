#include <iostream>

#include "CommandLine.hpp"

std::string	CommandLine::getInput() {
  char		tmpString[512];

  std::cin.getline(tmpString, sizeof(tmpString) / sizeof(char));
  return tmpString;
}
