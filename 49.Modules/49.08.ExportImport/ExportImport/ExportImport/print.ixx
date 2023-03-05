module;

export module print;

import <iostream>;
export import <vector>; // NEW_FOR_ME Way to forward <vector> to importers of module print
                        // So that importers can use std::vector

export {
  void greet(const std::string &name);

  void print_name_length(const char *c_str_name);
}