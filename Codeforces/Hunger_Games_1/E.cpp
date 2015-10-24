// LCM Query

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int A[20010];
vector<int> table[17][20010];
vector<int> primes;
vector<vector<int> > calc;
vector<int> factorization[61];
int ans[20010];
int t_table[100001];

#define PRIME_SIZE 17
#define MOD 1000000007

void smaller(vector<int>& a, vector<int>& b) {
  double x = 0, y = 0;
  for(int i = 0; i < PRIME_SIZE; i++) {
    x += log(primes[i]) * a[i];
    y += log(primes[i]) * b[i];
  }

  if(!(x < y)) a = b;
}

void precalc() {
  for(int i = 2; i <= 60; i++) {
    bool prime = true;
    for(int j = 2; j*j <= i; j++) {
      if(i % j == 0) {
        prime = false;
        break;
      }
    }
    if(prime) primes.push_back(i);
  }

  for(int i = 1; i <= 60; i++) {
    factorization[i].clear();
    int a = i;

    for(auto p: primes) {
      int cnt = 0;
      while(a % p == 0) {
        cnt++;
        a /= p;
      };
      factorization[i].push_back(cnt);
    }
  }

  for(int i = 1; i <= 30000; i++) {
    t_table[i] = int(log2(i));
  }
}

long long modpow(long long base, long long power) {
  long long result = 1;
  while(power > 0) {
    if(power & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return result;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  precalc();
  calc.resize(N + 10, vector<int>(PRIME_SIZE, 7));

  for(int i = 0; i < N; i++) {
    table[0][i] = factorization[A[i]];
  }

  int maxl = int(ceil(log2(N)));

  for(int i = 1; i <= maxl; i++) {
    for (int j = 0; j + (1 << i) - 1 < N; j++) {
      table[i][j].resize(PRIME_SIZE);
      for(int k = 0; k < PRIME_SIZE; k++) {
        table[i][j][k] = max(table[i - 1][j][k], table[i - 1][j + (1 << (i - 1))][k]);
      }
    }
  }

  for(int i = 0; i < N; i++) {
    int j = i;
    vector<int> curr = factorization[A[i]];

    while(j < N - 1) {
      int l = j + 1, r = N - 1;
      while(l < r) {
        int mid = (l + r)/2;

        int t = t_table[mid - i + 1];
        int p = 1 << t;
        vector<int> curr2(PRIME_SIZE);
        for(int k = 0; k < PRIME_SIZE; k++) {
          curr2[k] = max(table[t][i][k], table[t][mid - p + 1][k]);
        }

        if(curr == curr2) {
          l = mid + 1;
        }
        else {
          r = mid;
        }
      }
      if(l > N - 1) l = N - 1;

      smaller(calc[l - i], curr);

      int t = t_table[l - i + 1];
      int p = 1 << t;
      for(int k = 0; k < PRIME_SIZE; k++) {
        curr[k] = max(table[t][i][k], table[t][l - p + 1][k]);
      }

      j = l;
    }
    smaller(calc[N - i], curr);
  }

  for(int i = N + 10 - 2; i >= 0; i--) {
    smaller(calc[i], calc[i + 1]);

    ans[i] = 1;
    for(int j = 0; j < PRIME_SIZE; j++) {
      ans[i] = (ans[i] * modpow(primes[j], calc[i][j])) % MOD;
    }
  }

  while(M--) {
    int x; scanf("%d", &x);
    printf("%d\n", ans[x]);
  }
}
