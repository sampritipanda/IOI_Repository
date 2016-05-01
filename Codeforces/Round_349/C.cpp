#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

string S;
map<string, int> dp[10001];
int N;
set<string> ans;

int solve(int i, string prev) {
  if(i == N) return 1;
  if(dp[i].count(prev) > 0) return dp[i][prev];

  int curr_ans = 0;
  if(i + 2 <= N) {
    string S1 = "";
    S1 += S[i];
    S1 += S[i + 1];
    if(S1 != prev && solve(i + 2, S1)) {
      curr_ans = 1;
      ans.insert(S1);
    }
  }
  if(i + 3 <= N) {
    string S1 = "";
    S1 += S[i];
    S1 += S[i + 1];
    S1 += S[i + 2];
    if(S1 != prev && solve(i + 3, S1)) {
      curr_ans = 1;
      ans.insert(S1);
    }
  }

  dp[i][prev] = curr_ans;
  return curr_ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S;
  N = S.length();

  for(int i = 5; i < N; i++) {
    solve(i, "");
  }

  cout << ans.size() << endl;
  for(auto it: ans) {
    cout << it << endl;
  }
}
