#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, pair<int, int> > mp;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  while(N--) {
    string S; cin >> S;
    int M = S.length();
    if(S[M - 2] == 'k' && S[M - 1] == 'a') {
      S.pop_back();
      S.pop_back();
      mp[S].first++;
    }
    else if(S[M - 2] == 'k' && S[M - 1] == 'i') {
      S.pop_back();
      S.pop_back();
      mp[S].second++;
    }
  }

  int ans = 0;
  for(auto it: mp) {
    ans += min(it.second.first, it.second.second);
  }
  cout << ans << endl;
}
