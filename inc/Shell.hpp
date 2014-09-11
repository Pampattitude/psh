#ifndef __SHELL_HPP__
# define __SHELL_HPP__

# include "CommandLine.hpp"
# include "Environment.hpp"
# include "Prompt.hpp"

class	Shell {
public:
  Shell();

  bool	run(int ac, char **av, char **env);

  ~Shell();

private:
  Shell(Shell const &) = delete;
  Shell const	&operator=(Shell const &) = delete;

  Environment	*env_;

  Prompt	prompt_;
  CommandLine	commandLine_;
};

#endif
