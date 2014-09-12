#ifndef __COMMAND_LINE_HPP__
# define __COMMAND_LINE_HPP__

# include <list>
# include <string>

class CommandLine {
public:
  std::string	getInput();
  bool		eof() const;

private:
  std::list<std::string>	previousCommands_;
  bool				eof_ = false;
};

#endif
