#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long A[1000000];
long long P[1000000];

inline long long sum(int i, int j) {
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);

    for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

    sort(A, A + N);
    P[0] = A[0];
    for(int i = 1; i < N; i++) P[i] = P[i - 1] + A[i];
  }
}
