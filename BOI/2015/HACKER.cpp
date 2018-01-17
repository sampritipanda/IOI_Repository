#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int N;
int A[500000];
int P[500000];
int sum[500000];  // sum[i..(i+len)]
multiset<int> S;

int query(int i, int j) {
  if(i > j) {
    return query(i, N - 1) + query(0, j);
  }

  if(i == 0) return P[j];
  return P[j] - P[i - 1];
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  P[0] = A[0];
  for(int i = 1; i < N; i++) P[i] = P[i - 1] + A[i];

  int len = (N + 1)/2;
  for(int i = 0; i < N; i++) {
    sum[i] = query(i, (i + len - 1) % N);
  }

  int ans = 0;

  int L = 0 - (len - 1) + N, R = 0;
  int j = L;
  while(j != 1) {
    S.insert(sum[j]);
    j = (j + 1) % N;
  }

  for(int i = 0; i < N; i++) {
    ans = max(ans, *S.begin());
    S.erase(S.find(sum[L]));
    L = (L + 1) % N;
    R = (R + 1) % N;
    S.insert(sum[R]);
  }

  printf("%d\n", ans);
}
