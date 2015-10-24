// Cyclic shifts in permutation 

#include <stdio.h>
#include <vector>
#include <cassert>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int A[100001], B[100001];
long long bit[100001];
int N, K;

long long modpow(long long base, long long exp) {
  long long result = 1;
  while(exp > 0) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

long long query(int i) {
  int result = 0;
  while(i > 0) {
    result += bit[i];
    i -= i & -i;
  }
  return result;
}

void update(int i) {
  while(i <= N) {
    bit[i] += 1;
    i += i & -i;
  }
}

long long inv_count(int arr[]) {
  long long ans = 0;

  for(int i = 0; i <= N; i++) bit[i] = 0;
  for(int i = N - 1; i >= 0; i--) {
    ans += query(arr[i] - 1);
    update(arr[i]);
  }

  return ans;
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    for(int i = 0; i < N; i++) scanf("%d", &B[i]);

    long long x = inv_count(A) % 2, y = inv_count(B) % 2;

    if(K == N) {
      int ind;
      for(int i = 0; i < N; i++) {
        if(A[i] == B[0]) {
          ind = i;
          break;
        }
      }

      bool possible = true;
      for(int i = 0; i < N; i++) {
        if(A[(ind + i) % N] != B[i]) {
          possible = false;
          break;
        }
      }

      if(possible) printf("%d\n", B[0]);
      else printf("-1\n");
    }
    else {
      if(K % 2 == 0 || x == y) {
        for(int i = 0; i <= N; i++) bit[i] = 0;
        long long rank = 0, f = 1;
        for(int i = N - 1; i >= 0; i--) {
          int j = N - i - 1;
          if(j > 0) f = (f * j) % MOD;
          rank += (f * query(B[i] - 1)) % MOD;
          rank %= MOD;
          update(B[i]);
        }
        rank++; rank %= MOD;
        if(K & 1) {
          if(B[N - 2] < B[N - 1]) {
            rank = (rank + 1) % MOD;
          }
          rank = (rank * modpow(2, MOD - 2)) % MOD;
        }
        printf("%lld\n", rank);
      }
      else {
        printf("-1\n");
      }
    }
  }
}
