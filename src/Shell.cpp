#include <iostream>

#include "Shell.hpp"

Shell::Shell()
  : env_(nullptr), prompt_(), commandLine_()
{
}

// Main processing
bool	Shell::run(int, char **, char **env) {
  bool success = false;

  this->env_ = new Environment(env);

  // Main loop, stop when 'exit' builtin is called or ^D
  bool running = true;
  while (running) {
    try {
      if (!this->env_->hasEntry("PROMPT"))
	this->env_->setEntry("PROMPT", "$> ");
      this->prompt_.setFormat(this->env_->getEntry("PROMPT"));

      std::cout << this->prompt_.get();

      std::string input = this->commandLine_.getInput();
      if ("exit" == input)
	running = false;

      std::cout << input << std::endl;
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
      running = false;
      success = false;
    }
  }

  return success;
}

Shell::~Shell() {
  if (this->env_)
    delete this->env_;
}
