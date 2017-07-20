#include "cup.h"
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

map<pair<int, int>, int> memo;
int cnt;

int ask(int x, int y) {
  if(memo.find({x, y}) != memo.end()) return memo[{x, y}];
  cnt++;
  return memo[{x, y}] = ask_shahrasb(x, y);
}

vector<int> find_cup() {
  cnt = 0;
  memo.clear();
  int L_x = -5e8, R_x = +5e8;
  int d_x = ask(L_x, 0) ^ ask(R_x, 0);
  while(d_x != 0) {
    // printf("%d %d %d\n", L_x, R_x, cnt);
    int diff = 1 << __builtin_ctz(d_x);
    if(R_x + diff <= 1e9 && (memo.count({L_x, 0}) || L_x - diff < -1e9)) {
      if((ask(L_x, 0) ^ ask(R_x + diff, 0)) == (d_x - diff)) {
        L_x += diff;
      }
      else {
        R_x -= diff;
      }
    }
    else if(L_x - diff >= -1e9) {
      if((ask(L_x - diff, 0) ^ ask(R_x, 0)) == (d_x - diff)) {
        R_x -= diff;
      }
      else {
        L_x += diff;
      }
    }
    else {
      assert(d_x == (1 << 29));
      assert(diff == (1 << 29));

      int x_1 = ((L_x + (1 << 29)) + R_x)/2;
      int x_2 = (L_x + (R_x - (1 << 29)))/2;
      int y_1 = 5e8 - ask(x_1, 5e8);
      int y_2 = 5e8 - ask(x_2, 5e8);

      int test_x = -100, test_y = -100 + (1 << 29); // some random numbers
      if((abs(test_x - x_1) ^ abs(test_y - y_1)) == ask(test_x, test_y)) {
        L_x += 1 << 29;
      }
      else {
        R_x -= 1 << 29;
      }
    }
    d_x -= diff;
  }

  int x = (L_x + R_x)/2;
  int y = 5e8 - ask(x, 5e8);

  return {x, y};
}
