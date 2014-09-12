#include <iostream>

#include "CommandLine.hpp"

std::string	CommandLine::getInput() {
  char		tmpString[512];

  std::cin.getline(tmpString, sizeof(tmpString) / sizeof(char));
  if (std::cin.eof())
    this->eof_ = true;
  return tmpString;
}

bool		CommandLine::eof() const {
  return this->eof_;
}
