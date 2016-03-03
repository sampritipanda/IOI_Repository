#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int A[2001];
long long F[5001];
long long F2[10001];
long long F2_P[10001];

int main() {
  int N; cin >> N;;
  for(int i = 1; i <= N; i++) cin >> A[i];
  sort(A + 1, A + 1 + N);

  long long tot = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      tot++;
      F[A[j] - A[i]]++;
    }
  }

  for(int i = 0; i <= 5000; i++) {
    for(int j = 0; j <= 5000; j++) {
      F2[i + j] += F[i] * F[j];
    }
  }

  F2_P[0] = F2[0]; for(int i = 1; i <= 10000; i++) F2_P[i] = F2_P[i - 1] + F2[i];

  long long ans = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      ans += F2_P[A[j] - A[i] - 1];
    }
  }

  double prob = ans/double(tot*tot*tot);
  printf("%.8f\n", prob);
}
