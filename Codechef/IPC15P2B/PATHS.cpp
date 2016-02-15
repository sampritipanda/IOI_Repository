#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 1000001759;
const long long MOD3 = 1000002803;

long long dp1[2011][2011];
long long dp2[2011][2011];
long long dp3[2011][2011];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for(int i = 0; i <= 2000; i++) dp1[i][0] = dp2[i][0] = dp3[i][0] = 1;

  for(int i = 1; i <= 2000; i++) {
    for(int j = 1; j <= i; j++) {
      dp1[i][j] = (dp1[i - 1][j - 1] + dp1[i - 1][j]) % MOD1;
      dp2[i][j] = (dp2[i - 1][j - 1] + dp2[i - 1][j]) % MOD2;
      dp3[i][j] = (dp3[i - 1][j - 1] + dp3[i - 1][j]) % MOD3;
    }
  }

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;

    long long ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = 0; i < S.length(); i++) {
      ans1 = (ans1 * 10 + (S[i] - '0')) % MOD1;
      ans2 = (ans2 * 10 + (S[i] - '0')) % MOD2;
      ans3 = (ans3 * 10 + (S[i] - '0')) % MOD3;
    }

    set<pair<int, int> > list;
    for(int i = 1; i <= 1000; i++) {
      for(int j = 1; j <= 1000; j++) {
        int x = i - 1 + j - 1;
        int y = i - 1;
        if(dp1[x][y] == ans1 && dp2[x][y] == ans2 && dp3[x][y] == ans3) {
          list.insert({i, j});
        }
      }
    }

    if(list.size() == 0) {
      cout << "The Grid is Too Big!" << endl;
    }
    else {
      cout << list.size() << endl;
      for(auto it: list) {
        cout << it.first << " " << it.second << endl;
      }
    }
  }
}

