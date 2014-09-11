#include <cstdlib>
#include <iostream>

#include "Terminal.hpp"
#include "Shell.hpp"

int	main(int ac, char **av, char **env) {
  bool	success = false;

  try {
    Terminal	term;
    Shell	sh(term);
    success = sh.run(ac, av, env);
  }
  catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }
  catch (...) {
    std::cerr << "Unhandled exception thrown" << std::endl;
  }

  return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
