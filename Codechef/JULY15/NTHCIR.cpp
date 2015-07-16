// Rohith and Circles

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

long double ans[5];

int main() {
  int T; cin >> T;

  long long N_0, P, M, B; cin >> N_0 >> P >> M >> B;
  double R_1, R_2, R_3, R_4; cin >> R_1 >> R_2 >> R_3 >> R_4;

  long long N = N_0;
  ans[1] = -1/R_1, ans[2] = 1/R_2, ans[3] = 1/R_3, ans[4] = 1/R_4;

  double total = 0.0;
  while(T--) {
    N = (P * N) % M + B;
    double val = (N - 3) * ans[4] - (N - 4) * ans[3] + (ans[1] + ans[2]) * ((N - 4) * (N - 4 + 1));
    total += 1/val;
  }

  printf("%.6lf\n", total);
}
