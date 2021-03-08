#ifndef DOCOPTVALUEFMT
#define DOCOPTVALUEFMT

#include <fmt/format.h>
#include <docopt/docopt.h>
#include <string>
#include <string_view>

struct point { double x, y; };

template <> struct fmt::formatter<docopt::value>: formatter<string_view> {
  // parse is inherited from formatter<string_view>.
  template <typename FormatContext>
  auto format(docopt::value value, FormatContext& ctx) {
    string_view name = "unknown";
    if(!value){
      name = std::string_view("Empty");
    } else if(value.isString()){
        name = value.asString();
    } else if(value.isBool()){
      if(value.asBool()){
        name = std::string_view("true");
      } else{
        name = std::string_view("false");
      }
        // name = std::string_view(std::to_string(value.asBool()));
    } else if(value.isLong()){
        name = std::to_string(value.asLong());
    } else if(value.isStringList()){
        name = std::string_view("String list");
    }


    // switch (c) {
    // case color::red:   name = "red"; break;
    // case color::green: name = "green"; break;
    // case color::blue:  name = "blue"; break;
    // }
    return formatter<string_view>::format(name, ctx);
  }
};

#endif