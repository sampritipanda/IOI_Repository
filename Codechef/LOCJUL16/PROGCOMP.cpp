#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#define MOD 1000000007

using namespace std;

long long fact[100001];
int F[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i <= 100000; i++) fact[i] = (fact[i - 1] * i) % MOD;

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    for(int i = 0; i < 26; i++) F[i] = 0;
    for(char c: S) {
      F[c - 'a']++;
    }

    long long ans = 1;
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
      if(F[i] == 0) continue;
      cnt++;
      ans *= fact[F[i]];
      ans %= MOD;
    }
    ans *= fact[cnt];
    ans %= MOD;

    cout << ans << endl;
  }
}
