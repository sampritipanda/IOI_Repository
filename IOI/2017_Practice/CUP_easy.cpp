#include "cup.h"
#include <algorithm>

using namespace std;

vector<int> find_cup() {
  int diff = ask_shahrasb(5e8, 5e8);
  int ans = 0;
  for(int i = 0; i <= 28; i++) {
    if(ask_shahrasb(5e8 + (1 << i), 5e8) != (diff ^ (1 << i))) {
      ans += 1 << i;
    }
  }
  int x_1 = 5e8 - ans;
  int y_1 = 5e8 - (ans ^ diff);

  ans += 1 << 29;
  int x_2 = 5e8 - ans;
  int y_2 = 5e8 - (ans ^ diff);

  int test_x = -100, test_y = -100 + (1 << 29); // some random numbers
  if((abs(test_x - x_1) ^ abs(test_y - y_1)) == ask_shahrasb(test_x, test_y)) {
    return {x_1, y_1};
  }
  else {
    return {x_2, y_2};
  }
}
