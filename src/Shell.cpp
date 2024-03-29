#include <boost/algorithm/string/trim_all.hpp>
#include <iostream>

#include "Exception.hpp"
#include "Shell.hpp"

// TMP
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <cstring>
#include <sys/wait.h>
// EOTMP

Shell::Shell(Terminal &t)
  : term_(t), env_(nullptr), prompt_(), commandLine_()
{
}

// TMP
bool	exec(std::string const &input, Environment &env) {
  std::vector<std::string>	commandTable;
  boost::split(commandTable, input, boost::is_any_of(" \t"));

  if (!commandTable.size())
    return false;

  char **args = new char*[commandTable.size() + 1];
  for (int unsigned i = 0 ; commandTable.size() > i ; ++i) {
    args[i] = new char[commandTable[i].length() + 1];
    strcpy(args[i], commandTable[i].c_str());
  }
  args[commandTable.size()] = nullptr;

  std::string	executableFile;

  std::string	path = env.getEntry("PATH");
  std::vector<std::string>	pathList;

  if (!path.length())
    boost::split(pathList, "/bin/:/usr/bin/", boost::is_any_of(":"));
  else
    boost::split(pathList, path, boost::is_any_of(":"));

  for (int unsigned i = 0 ; pathList.size() > i ; ++i) {
    bool slash = false;
    if ('/' == pathList[i][pathList[i].length() - 1])
      slash = true;

    if (boost::filesystem::exists(std::string(pathList[i]) + (slash ? "" : "/") + args[0])) {
      executableFile += pathList[i];
      if (!slash)
	executableFile += '/';
      executableFile += args[0];

      break ;
    }
  }

  int	childPid = fork();
  if (0 == childPid) {
    execv(executableFile.c_str(), args);
    throw UntypedException(strerror(errno));
  }

  int	status;
  wait(&status);
  return EXIT_SUCCESS == status;
}
// EOTMP

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

      this->term_.write(this->prompt_.get());

      std::string input = this->commandLine_.getInput();
      if (this->commandLine_.eof()) {
	this->term_.write("^D").write(Terminal::endl).write("exit").write(Terminal::endl);
	break ;
      }
      boost::trim_all(input);

      // TMP
      if (!exec(input, *this->env_)) {
#ifdef DEBUG
	this->term_.write(std::string("\"") + input + "\" command failed").write(Terminal::endl);
#endif
      }
      // EOTMP

      // TMP
      if ("exit" == input) {
	this->term_.write(input).write(Terminal::endl);
	running = false;
      }
      // EOTMP
    }
    catch (std::exception const &e) {
      std::cerr << e.what() << std::endl;
      running = false;
      success = false;
    }
  }

  if (this->env_) {
    delete this->env_;
    this->env_ = nullptr;
  }

  return success;
}

Shell::~Shell() {
  if (this->env_) {
    delete this->env_;
    this->env_ = nullptr;
  }
}
