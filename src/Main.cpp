#include <cstdlib>
#include <iostream>

#include "Shell.hpp"

int	main(int ac, char **av, char **env) {
  bool	success = false;

  try {
    Shell	sh;
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
