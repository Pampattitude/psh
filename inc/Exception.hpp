
#ifndef __EXCEPTION_HPP__
# define __EXCEPTION_HPP__

# include <exception>

# define ExceptionClass(className, text)	class className: public std::exception {\
public:\
char const	*what() const noexcept { return text; }\
  }

ExceptionClass(InvalidEnvironmentEntry, "Invalid entry in environment");
ExceptionClass(UnknownEnvironmentEntry, "Unknown entry in environment");

#endif
