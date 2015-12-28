#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

unordered_map<int, int> ways[101][101]; // ways[i][j][k] = number of ways to make sum i with first j land plots and profit k
int A[101], B[101], C[101];

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    int N, S; cin >> N >> S;

    for(int i = 0; i <= S; i++)
      for(int j = 0; j <= N; j++)
        ways[i][j].clear();

    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];

    for(int i = 0; i <= N; i++) ways[0][i][0] = 1;

    for(int i = 1; i <= S; i++) {
      for(int j = 1; j <= N; j++) {
        for(int k = 0; k*A[j] <= i; k++) {
          for(auto p: ways[i - k*A[j]][j - 1]) {
            ways[i][j][p.first + (C[j] - B[j]) * k] += p.second;
            ways[i][j][p.first + (C[j] - B[j]) * k] %= MOD;
          }
        }
      }
    }

    // for(int i = 0; i <= S; i++) {
    //   for(int j = 0; j <= N; j++) {
    //     for(auto p: ways[i][j]) {
    //       cout << i << " " << j << ": " << p.first << " " << p.second << endl;
    //     }
    //   }
    // }

    int ans = 0;
    for(int i = 1; i <= S; i++) {
      for(auto p: ways[i][N]) {
        if(p.first > 0) ans += p.second;
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
}
