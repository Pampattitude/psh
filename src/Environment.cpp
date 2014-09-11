#include <utility>

#include "Environment.hpp"
#include "Exception.hpp"

Environment::Environment(char **env)
  : entries_()
{
  while (*env) {
    std::string	entry = *env;

    auto it = entry.find('=');
    if (size_t(-1) == it)
      throw InvalidEnvironmentEntry();

    this->entries_.insert(std::pair<std::string, std::string>(entry.substr(0, it), entry.substr(it + 1, entry.size() - it - 1)));

    ++env;
  }
}

std::string const	&Environment::getEntry(std::string const &key) const {
  std::map<std::string, std::string>::const_iterator	it = this->entries_.find(key);

  if (this->entries_.end() == it)
    throw UnknownEnvironmentEntry();
  return it->second;
}

bool			Environment::hasEntry(std::string const &key) const {
  std::map<std::string, std::string>::const_iterator	it = this->entries_.find(key);
  return this->entries_.end() != it;
}

void			Environment::setEntry(std::string const &key, std::string const &val) {
  this->entries_[key] = val;
}
