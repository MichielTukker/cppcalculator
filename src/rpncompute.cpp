#include <rpncompute.hpp>

#include <sstream>
#include <vector>
#include <iostream>
#include <cctype>
#include <cmath>
#include <iterator>

RpnCompute::RpnCompute()
{
}

double RpnCompute::Parse(const std::string &expr)
{
  std::istringstream input_stream(expr);
  std::vector<double> operands;

  std::cout << "Input\tOperation\tStack after\n";

  std::string token;

  while (input_stream >> token) {
    std::cout << token << "\t";
    double number_token;
    if (std::istringstream(token) >> number_token) {
      std::cout << "Push\t\t";
      operands.push_back(number_token);
    } else {
      std::cout << "Operate\t\t";
      double secondOperand = operands.back();
      operands.pop_back();
      double firstOperand = operands.back();
      operands.pop_back();
      if (token == "*")
        operands.push_back(firstOperand * secondOperand);
      else if (token == "/")
        operands.push_back(firstOperand / secondOperand);
      else if (token == "-")
        operands.push_back(firstOperand - secondOperand);
      else if (token == "+")
        operands.push_back(firstOperand + secondOperand);
      else if (token == "^")
        operands.push_back(std::pow(firstOperand, secondOperand));
      else {//just in case
        std::cerr << "Error" << std::endl;
        std::exit(1);
      }
    }
    std::copy(operands.begin(), operands.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
  }
  return operands.back();
}