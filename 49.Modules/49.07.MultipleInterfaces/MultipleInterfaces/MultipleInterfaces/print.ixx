module;

export module print;

import <iostream>;

export {
  void greet(const std::string &name);

  void print_name_length(const char *c_str_name);
}