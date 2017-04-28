#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<vector<int> > mat_mul(vector<vector<int> >& A, vector<vector<int> >& B) {
  vector<vector<int> > C(A.size(), vector<int>(B[0].size()));
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < B[0].size(); j++) {
      for(int k = 0; k < A[0].size(); k++) {
        C[i][j] += (1LL * A[i][k] * B[k][j]) % MOD;
        C[i][j] %= MOD;
      }
    }
  }
  return C;
}

vector<vector<int> > mult[41][20];
int dp[40], tmp[40];

int main() {
  for(int M = 1; M <= 40; M++) {
    vector<vector<int> > even(M, vector<int>(M));
    vector<vector<int> > odd(M, vector<int>(M));

    for(int i = 0; i < M; i++) {
      for(int j = 0; j < M; j++) {
        if(i < j) even[i][j] = 1;
        if(i > j) odd[i][j] = 1;
      }
    }

    mult[M][0] = mat_mul(even, odd);
    for(int i = 1; i < 20; i++) mult[M][i] = mat_mul(mult[M][i - 1], mult[M][i - 1]);
  }

  int Q; cin >> Q;
  while(Q--) {
    int N, M; cin >> N >> M; N--;
    for(int i = 0; i < M; i++) dp[i] = 1;

    for(int i = 0; i < 20; i++) {
      if(!((N/2) & (1 << i))) continue;

      for(int j = 0; j < M; j++) {
        tmp[j] = 0;
        for(int k = 0; k < M; k++) {
          tmp[j] += (1LL * dp[k] * mult[M][i][k][j]) % MOD;
          tmp[j] %= MOD;
        }
      }
      for(int j = 0; j < M; j++) dp[j] = tmp[j];
    }

    if(N % 2 == 1) {
      for(int j = 0; j < M; j++) {
        tmp[j] = 0;
        for(int k = 0; k < j; k++) {
          tmp[j] = (tmp[j] + dp[k]) % MOD;
        }
      }
      for(int j = 0; j < M; j++) dp[j] = tmp[j];
    }

    int ans = 0;
    for(int j = 0; j < M; j++) ans = (ans + dp[j]) % MOD;
    cout << ans << endl;
  }
}
