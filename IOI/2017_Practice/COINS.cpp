#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
  int val = 0;
  for(int i = 0; i < 64; i++) {
    if(b[i]) val ^= i;
  }
  return {val ^ c};
}

int find_coin(std::vector<int> b) {
  int val = 0;
  for(int i = 0; i < 64; i++) {
    if(b[i]) val ^= i;
  }
  return val;
}
