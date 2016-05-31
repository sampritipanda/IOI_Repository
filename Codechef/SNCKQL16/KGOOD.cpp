#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int F[26];
int C[26];
multiset<int> F_S;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    for(int i = 0; i < 26; i++) F[i] = C[i] = 0;

    string S; int K; cin >> S >> K;
    int N = S.length();

    for(char c: S) {
      F[c - 'a']++;
    }

    F_S.clear();
    for(int i = 0; i < 26; i++) {
      if(F[i]) F_S.insert(F[i]);
    }

    int ans = 0;
    while(true) {
      int mn = *F_S.begin(), mx = *F_S.rbegin();
      if(mx - mn <= K) break;

      ans += (mx - mn) - K;
      F_S.erase(F_S.find(mx));
      F_S.insert(mn + K);
    }

    F_S.clear();
    for(int i = 0; i < 26; i++) {
      if(F[i]) F_S.insert(F[i]);
    }

    int ans2 = 0;
    while(true) {
      int mn = *F_S.begin(), mx = *F_S.rbegin();
      if(mx - mn <= K) break;

      ans2 += mn;
      F_S.erase(F_S.find(mn));
    }

    cout << min(ans, ans2) << endl;
  }
}
