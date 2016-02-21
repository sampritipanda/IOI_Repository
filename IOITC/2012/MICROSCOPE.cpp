#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M, N; scanf("%d %d", &M, &N);
  int R, C; scanf("%d %d", &R, &C);

  int K; scanf("%d", &K);

  int x0 = 0, y0 = 0;
  int x1 = R - 1, y1 = C - 1;

  long long ans = 0;

  while(K--) {
    int x, y; scanf("%d %d", &x, &y);

    if(x >= x0 && x <= x1 && y >= y0 && y <= y1) continue;

    if(x > x1) {
      int dx = x - x1;
      ans += dx;
      x1 += dx; x0 += dx;
    }
    else if(x < x0) {
      int dx = x0 - x;
      ans += dx;
      x1 -= dx; x0 -= dx;
    }

    if(y > y1) {
      int dy = y - y1;
      ans += dy;
      y1 += dy; y0 += dy;
    }
    else if(y < y0) {
      int dy = y0 - y;
      ans += dy;
      y1 -= dy; y0 -= dy;
    }
  }

  printf("%lld\n", ans);
}
