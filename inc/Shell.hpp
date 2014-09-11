#ifndef __SHELL_HPP__
# define __SHELL_HPP__

# include "CommandLine.hpp"
# include "Environment.hpp"
# include "Prompt.hpp"
# include "Terminal.hpp"

class	Shell {
public:
  Shell(Terminal &);

  bool	run(int ac, char **av, char **env);

  ~Shell();

private:
  Shell(Shell const &) = delete;
  Shell(Shell &&) = delete;
  Shell const	&operator=(Shell const &) = delete;
  Shell		&operator=(Shell &&) = delete;

  Terminal	&term_;
  Environment	*env_;

  Prompt	prompt_;
  CommandLine	commandLine_;
};

#endif
