#include <catch2/catch.hpp>

#include <rpncompute.hpp>

TEST_CASE("check parsing", "[rpn_parse]")
{
  std::string s = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
  auto rpn = RpnCompute();
  auto answer = rpn.Parse(s);
  REQUIRE( (answer - 3.00012) < 1e-4 );
}