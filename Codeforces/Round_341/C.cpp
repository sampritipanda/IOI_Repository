#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int L[100002], R[100002];
double P[100002];   // P[i] = Probability of divisible by p

int count(int L, int R, int x) {
  return max(floor(R/double(x)) - ceil(L/double(x)) + 1, 0.0);
}

int main() {
  ios::sync_with_stdio(false);

  int N, p; cin >> N >> p;
  for(int i = 1; i <= N; i++) cin >> L[i] >> R[i];

  L[0] = L[N]; R[0] = R[N];
  L[N + 1] = L[1]; R[N + 1] = R[1];

  for(int i = 0; i <= N + 1; i++) {
    P[i] = count(L[i], R[i], p)/double(R[i] - L[i] + 1);
  }

  double ans = 0;

  for(int i = 1; i <= N; i++) {
    ans += (P[i] + P[i - 1] - P[i] * P[i - 1]) * 1000;
    ans += (P[i] + P[i + 1] - P[i] * P[i + 1]) * 1000;
  }

  printf("%.7f\n", ans);
}
