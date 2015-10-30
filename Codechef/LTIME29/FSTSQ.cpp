// Fast squarer

#include <cstdio>
#include <algorithm>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<int> res, pref, suff, ans;

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    res.clear(); pref.clear(); suff.clear(); ans.clear();

    int N, D; scanf("%d %d", &N, &D);

    int carry = 0;
    for(int i = 1; i <= N; i++) {
      int curr = D * D + carry;
      res.push_back(curr % 10);
      carry = curr/10;
    }
    if(carry > 0) res.push_back(carry);
    reverse(res.begin(), res.end());

    pref.resize(res.size()); suff.resize(res.size());
    pref[0] = res[0]; for(int i = 1; i < res.size(); i++) pref[i] = pref[i - 1] + res[i];
    suff[res.size() - 1] = res[res.size() - 1]; for(int i = res.size() - 2; i >= 0; i--) suff[i] = suff[i + 1] + res[i];

    carry = 0;
    for(int i = res.size() - 1; i >= (D > 3 ? 1 : 0); i--) {
      int curr = suff[i] + carry;
      ans.push_back(curr % 10);
      carry = curr / 10;
    }
    for(int i = res.size() - 2; i >= 0; i--) {
      int curr = pref[i] + carry;
      ans.push_back(curr % 10);
      carry = curr / 10;
    }
    if(carry > 0) ans.push_back(carry);

    long long h = 0, p = 1;
    for(int i = ans.size() - 1; i >= 0; i--) {
      h += (p * ans[i]) % MOD;
      h %= MOD;
      p = (p * 23) % MOD;
    }
    printf("%lld\n", h);
  }
}
