#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int C[100000];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, L, R; scanf("%d %d %d", &N, &L, &R);
    for(int i = 0; i < N; i++) {
      scanf("%d", &C[i]);
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
      sum += C[i];
      if(sum > R + 1) break;
    }

    int curr = L % sum;
    int j = 0;
    for(; j < N; j++) {
      if(curr - C[j] < 0) break;
      curr -= C[j];
    }

    if(L != R) {
      double ans = 0.0;
      int sz = R - L;

      double step = 0.0;
      if(sz >= 1e9) step = 1e0;
      else if(sz >= 1e8) step = 1e-1;
      else if(sz >= 1e7) step = 1e-2;
      else if(sz >= 1e6) step = 1e-2;
      else if(sz >= 1e5) step = 1e-3;
      else if(sz >= 1e4) step = 1e-4;
      else if(sz >= 1e3) step = 1e-5;
      else step = 1e-7;
      /*
         else if(sz >= 1e2) step = 1e-7;
         else if(sz >= 1e1) step = 1e-8;
         else step = 1e-9;
         */

      for(int i = L; i < R; i++) {
        for(double j = 0.0; j < 1; j += step) {
          ans += (curr + j);
        }
        curr++;
        if(curr == C[j]) {
          j++;
          curr = 0;
          if(j == N) j = 0;
        }
      }

      double top = ans;
      double down = sz/step + 1;

      printf("Case #%d: %.10lf\n", t, top/down);
    }
    else {
      printf("Case #%d: %.10lf\n", t, (double)curr);
    }
  }
}
