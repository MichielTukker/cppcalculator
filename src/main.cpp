#include <iostream>
#include <rpncompute.hpp>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>
#include <docopt_value_fmt.hpp>

static constexpr auto VERSION = "Calculator 1.17";
static constexpr auto USAGE =
  R"(Calculator

  Usage:
    calcu compute <expression>
    calcu parse 

  Options:
    -h --help     Show this screen.
    --version     Show version.
    --rpn         Reverse Polish Notation.
)";

int main(int argc, char **argv)
{
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    VERSION);// version string

  for (auto const &arg : args) {
    spdlog::debug("Variable: {0} = {1}", arg.first, arg.second);
    // std::cout << arg.first << " " << arg.second << std::endl;
  }

  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::debug("Hello, {}!", "World");
  spdlog::info("Hello, {}!", "World");
  fmt::print("Hello, from {}\n", "{fmt}");


  std::string s = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
  auto rpn = RpnCompute();
  auto answer = rpn.Parse(s);
  spdlog::info("Final answer = {}", answer);

  return 0;
}