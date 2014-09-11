#ifndef __TERMINAL_HPP__
# define __TERMINAL_HPP__

# include <iostream>

class	Terminal {
public:
  static std::string    endl;


  Terminal();

  template<typename T>
  Terminal	&write(T const &t) {
    (*this->output_) << t;
    return *this;
  }
  template<typename T>
  Terminal	&read(T &t) {
    (*this->input_) >> t;
    return *this;
  }

private: // Non-copiable (should be movable?)
  Terminal(Terminal const &) = delete;
  Terminal(Terminal &&) = delete;
  Terminal const	&operator=(Terminal const &) = delete;
  Terminal		&operator=(Terminal &&) = delete;

private:
  std::istream	*input_;
  std::ostream	*output_;
};

#endif
