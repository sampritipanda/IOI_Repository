#include <iostream>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

int ways[101][101][20001]; // ways[i][j][k] = number of ways to make sum i with first j land plots and profit k
int A[101], B[101], C[101];

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    int N, S; cin >> N >> S;

    for(int i = 0; i <= S; i++)
      for(int j = 0; j <= N; j++)
        for(int k = 0; k <= 20000; k++)
          ways[i][j][k] = 0;

    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];

    ways[0][0][10000] = 1;
    A[0] = 10000;

    for(int i = 0; i <= S; i++) {
      for(int j = 0; j <= N; j++) {
        for(int k = -10000; k <= 9901; k++) {
          if(ways[i][j][k + 10000] == 0) continue;

          if(i + A[j] <= S) {
            int new_prof = k + (C[j] - B[j]);
            if(new_prof > 9900) new_prof = 9901;
            ways[i + A[j]][j][new_prof + 10000] = (((long long)ways[i][j][k + 10000]) + ways[i + A[j]][j][new_prof + 10000]) % MOD;
          }
          if(j < N) {
            ways[i][j + 1][k + 10000] = (((long long)ways[i][j][k + 10000]) + ways[i][j + 1][k + 10000]) % MOD;
          }
        }
      }
    }

    long long ans = 0;
    for(int i = 1; i <= S; i++) {
      for(int k = 1; k <= 9901; k++) {
        ans += ways[i][N][k + 10000];
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
}
