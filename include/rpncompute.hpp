#ifndef RPNCOMPUTE
#define RPNCOMPUTE

#include <string>

class RpnCompute
{
public:
  RpnCompute();
  double Parse(const std::string &expr);

private:
};

#endif