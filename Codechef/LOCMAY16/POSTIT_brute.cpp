#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <string>
#include <cassert>
#include <climits>
#include <cmath>

using namespace std;

string S;
long long N, K, M;
long long F[26], F2[26];
vector<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S;
  N = S.length();
  cin >> K >> M;

  for(char c: S) F[c - 'a']++;

  assert(M < N);

  long long ans2 = LLONG_MAX/2;
  string S2 = "";

  for(int mask = 0; mask < (1 << N); mask++) {
    if(__builtin_popcount(mask) != M) continue;

    for(int i = 0; i < 26; i++) F2[i] = 0;

    string T = "";
    for(int i = 0; i < N; i++) {
      if(mask & (1 << i)) {
        T += S[i];
        F2[S[i] - 'a']++;
      }
    }
    sort(T.begin(), T.end());

    bool pos = true;
    for(int i = 0; i < 26; i++) {
      if(F[i] > 0 && F2[i] == 0) pos = false;
    }
    if(pos) {
      long long ans = 0;
      for(int i = 0; i < 26; i++) {
        ans = max(ans, (long long)ceil((F[i] * K)/double(F2[i])));
      }
      if(ans < ans2) {
        S2 = T;
        ans2 = ans;
      }
      else if(ans == ans2 && T < S2) {
        S2 = T;
      }
    }
  }
  if(ans2 == LLONG_MAX/2) cout << -1 << endl;
  else cout << ans2 << endl << S2 << endl;
}
