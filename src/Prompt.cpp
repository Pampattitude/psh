#include "Prompt.hpp"

void	Prompt::setFormat(std::string const &s) {
  this->raw_ = s;
}

std::string const	&Prompt::get() const {
  // TODO: Process raw string
  return this->raw_;
}
