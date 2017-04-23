#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string S, T;
int N, M;
int Z[600000];
int dp[300001];  // dp[i] = max index such that i..dp[i] is good

int main() {
  cin >> S >> T;
  N = S.length(); M = T.length();

  for(int i = 0; i < M; i++) {
    Z[i] = i - 1;
    for(int j = i; j < M && (j - i + 1) <= N; j++) {
      if(S.substr(0, j - i + 1) == T.substr(i, j - i + 1)) {
        Z[i] = j;
      }
      else {
        break;
      }
    }
  }

  dp[M] = M - 1;
  for(int i = M - 1; i >= 0; i--) {
    dp[i] = i - 1;
    for(int j = i; j <= Z[i]; j++) {
      dp[i] = max(dp[i], dp[j + 1]);
    }
  }

  int Q; cin >> Q;

  while(Q--) {
    int L, R; cin >> L >> R; L--; R--;
    if(dp[L] >= R) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
