#ifndef __PROMPT_HPP__
# define __PROMPT_HPP__

# include <string>

class Prompt {
public:
  void			setFormat(std::string const &);
  std::string const	&get() const;

private:
  std::string	raw_;
};

#endif
