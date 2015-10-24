#include <iostream>
#include <algorithm>

using namespace std;

int ans;
string result;

int solve2(int x1, int y1, int x2, int y2, int x3, int y3) {
  if(y1 == y2 && y2 == y3 && (x1 + x2 + x3) == y1) return 1;
  if(x1 == x2 && x2 == x3 && (y1 + y2 + y3) == x1) return 2;
  if(x1 == (x2 + x3) && y2 == y3 && x1 == (y1 + y2)) return 3;
  if(x2 == (x1 + x3) && y1 == y3 && x2 == (y1 + y3)) return 4;
  if(x3 == (x1 + x2) && y1 == y2 && x3 == (y1 + y2)) return 4;
}

int solve(int x1, int y1, int x2, int y2, int x3, int y3) {
  for(int mask = 0; mask < (1 << 3); mask++) {
    if(mask & (1 << 0)) swap(x1, y1);
    if(mask & (1 << 1)) swap(x2, y2);
    if(mask & (1 << 2)) swap(x3, y3);

    int ans = solve2(x1, y1, x2, y2, x3, y3);
    if(ans != -1) return ans;

    if(mask & (1 << 0)) swap(x1, y1);
    if(mask & (1 << 1)) swap(x2, y2);
    if(mask & (1 << 2)) swap(x3, y3);
  }

  return -1;
}

int main() {
  int x1, y1, x2, y2, x3, y3;

  cout << solve(x1, y1, x2, y2, x3, y3) << endl;
}
