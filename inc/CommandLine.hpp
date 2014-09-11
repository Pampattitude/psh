#ifndef __COMMAND_LINE_HPP__
# define __COMMAND_LINE_HPP__

# include <list>
# include <string>

class CommandLine {
public:
  std::string	getInput();

private:
  std::list<std::string>	previousCommands_;
};

#endif
