#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

#define MOD 1000000009

int A[300001];
int A_P[300001];
int F[300001];
int F_P[300001];
int Q_P[300005];
vector<pair<int, int> > upd;

inline int reduce(int x) {
  assert(x >= INT_MIN && x <= INT_MAX);
  while(x < MOD) x += MOD;
  return x % MOD;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  F[0] = 0; F[1] = 1;
  for(int i = 2; i <= N; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;
  for(int i = 1; i <= N; i++) F_P[i] = (F_P[i - 1] + F[i]) % MOD;

  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for(int i = 1; i <= N; i++) A_P[i] = (A_P[i - 1] + A[i]) % MOD;

  int buffer = int(sqrt(M));
  while(M--) {
    int t, L, R; scanf("%d %d %d", &t, &L, &R);

    if(t == 2) {
      int ans = reduce(A_P[R] - A_P[L - 1]);
      for(auto u: upd) {
        int qL = u.first, qR = u.second;
        if(qL > R || qR < L) continue;
        else if(L <= qL && qR <= R) {
          (ans += F_P[qR - qL + 1]) %= MOD;
        }
        else if(qL <= L && R <= qR) {
          (ans += reduce(F_P[R - qL + 1] - F_P[(L - qL + 1) - 1])) %= MOD;
        }
        else if(L >= qL && R >= qR) {
          (ans += reduce(F_P[qR - qL + 1] - F_P[(L - qL + 1) - 1])) %= MOD;
        }
        else if(L <= qL && R <= qR) {
          (ans += F_P[R - qL + 1]) %= MOD;
        }
      }
      printf("%d\n", ans % MOD);
    }
    else {
      upd.push_back({L, R});
      (Q_P[L] += 1) %= MOD;
      Q_P[R + 1] = reduce(Q_P[R + 1] - reduce(F[R - L + 1] + F[(R - L + 1) - 1]));
      Q_P[R + 2] = reduce(Q_P[R + 2] - F[R - L + 1]);
    }

    if(upd.size() == buffer) {
      (A[1] += Q_P[1]) %= MOD;
      for(int i = 2; i <= N; i++) {
        (Q_P[i] += reduce(Q_P[i - 1] + Q_P[i - 2])) %= MOD;
        (A[i] += Q_P[i]) %= MOD;
      }
      for(int i = 1; i <= N; i++) {
        A_P[i] = (A_P[i - 1] + A[i]) % MOD;
        Q_P[i] = 0;
      }
      upd.clear();
    }
  }
}
