#ifndef __ENVIRONMENT_HPP__
# define __ENVIRONMENT_HPP__

# include <map>
# include <string>

class	Environment {
public:
  Environment(char **);

  std::string const	&getEntry(std::string const &) const;
  bool			hasEntry(std::string const &) const;
  void			setEntry(std::string const &, std::string const &);

private:
  std::map<std::string, std::string>	entries_;
};

#endif
