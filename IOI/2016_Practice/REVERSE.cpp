#include "reverse.h"
#include <algorithm>

std::vector<long long> reverse(const std::vector<long long> &a) {
  std::vector<long long> B = a;
  std::reverse(B.begin(), B.end());
  return B;
}

