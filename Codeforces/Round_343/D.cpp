#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define PI 3.1415926535

long long R[100001], H[100001];
long long V[100001], dp[100001];
map<long long, int> M;
long long bit[100001];

long long query(int i) {
  long long ans = 0;
  while(i > 0) {
    ans = max(ans, bit[i]);
    i -= i & -i;
  }
  return ans;
}

void update(int i, long long v) {
  while(i <= 100000) {
    bit[i] = max(bit[i], v);
    i += i & -i;
  }
}

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> R[i] >> H[i];
    V[i] = R[i] * R[i] * H[i];
    M[V[i]] = 0;
  }

  int id = 0;
  for(auto it: M) {
    M[it.first] = ++id;
  }

  for(int i = 1; i <= N; i++) {
    if(i == 5000) {
      int a = 4;
    }
    dp[i] = V[i];
    dp[i] = max(dp[i], V[i] + query(M[V[i]] - 1));
    update(M[V[i]], dp[i]);
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans = max(ans, dp[i]);
  printf("%.8f\n", PI * ans);
}
