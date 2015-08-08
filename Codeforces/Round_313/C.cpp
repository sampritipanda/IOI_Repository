#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long factorial[1000000];
long long ans[10000];
vector<pair<int, int> > S;

long long modpow(long long base, long long exp) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return result;
}

long long F(int x1, int y1, int x2, int y2) {
  int x = x2 - x1 - 1;
  int y = y2 - y1 - 1;

  long long ans = factorial[x + y];
  long long denom = (factorial[x] * factorial[y]) % MOD;
  ans = (ans * modpow(denom, MOD - 2)) % MOD;
  return ans;
}

int main() {
  S.clear();

  int h, w, n; cin >> h >> w >> n;

  for(int i = 0; i < n; i++) {
    int r, c; cin >> r >> c;
    S.push_back({r, c});
  }

  S.push_back({h, w});
  n++;

  sort(S.begin(), S.end());

  factorial[0] = 1;
  for(int i = 1; i <= 1000000; i++) factorial[i] = (factorial[i - 1] * i) % MOD;

  for(int i = 0; i < n; i++) ans[i] = F(1, 1, S[i].first, S[i].second);

  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      if(S[j].first < S[i].first || S[j].second < S[i].second) continue;

      long long sub = (ans[i] * F(S[i].first, S[i].second, S[j].first, S[j].second)) % MOD;
      ans[j] -= sub;
      while(ans[j] < 0) ans[j] += MOD;
      ans[j] %= MOD;
    }
  }

  cout << ans[n - 1] << endl;
}
