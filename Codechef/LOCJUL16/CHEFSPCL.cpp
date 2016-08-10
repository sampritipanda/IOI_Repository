#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int S[20];
int _K;
long long dp[20][2][7][7][7][7][7][7];

long long solve_k(int i, int j, int m_1, int m_2, int m_3, int m_4, int m_5, int m_6) {
  if(i == 0) return 1;
  if(dp[i][j][m_1][m_2][m_3][m_4][m_5][m_6] != -1) return dp[i][j][m_1][m_2][m_3][m_4][m_5][m_6];
  // cout << i << " " << j << " " << m_1 << " " << m_2 << " " << m_3 << " " << m_4 << " " << m_5 << " " << m_6 << endl;

  int M[] = {0, m_1, m_2, m_3, m_4, m_5, m_6};
  long long curr = 0;
  if(j == 0) {
    for(int d = 1; d <= S[i]; d++) {
      int d2 = d % _K;
      if(d2 == 0) continue;
      bool pos = true;
      for(int mod = 1; mod < _K; mod++) {
        if(M[mod] > 0 && (10 * mod + d2) % _K == 0) {
          pos = false;
          break;
        }
      }
      if(!pos) continue;
      int M2[7] = {0, 0, 0, 0, 0, 0, 0};
      for(int mod = 1; mod < _K; mod++) {
        M2[(10 * mod + d2) % _K] += M[mod];
      }
      M2[d2]++;
      curr += solve_k(i - 1, (d == S[i] ? 0 : 1), M2[1], M2[2], M2[3], M2[4], M2[5], M2[6]);
    }
  }
  else {
    for(int d = 1; d <= 9; d++) {
      int d2 = d % _K;
      if(d2 == 0) continue;
      bool pos = true;
      for(int mod = 1; mod < _K; mod++) {
        if(M[mod] > 0 && (10 * mod + d2) % _K == 0) {
          pos = false;
          break;
        }
      }
      if(!pos) continue;
      int M2[7] = {0, 0, 0, 0, 0, 0, 0};
      for(int mod = 1; mod < _K; mod++) {
        M2[(10 * mod + d2) % _K] += M[mod];
      }
      M2[d2]++;
      curr += solve_k(i - 1, 1, M2[1], M2[2], M2[3], M2[4], M2[5], M2[6]);
    }
  }

  return dp[i][j][m_1][m_2][m_3][m_4][m_5][m_6] = curr;
}

long long solve(int K, long long A) {
  if(A == 0) return 0;
  _K = K;

  memset(S, 0, sizeof S);

  cout << A << " ";

  int N = 0;
  while(A > 0) {
    S[++N] = A % 10;
    A /= 10;
  }

  cout << N << endl;

  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    long long curr = solve_k(i, (i < N ? 1 : 0), 0, 0, 0, 0, 0, 0);
    ans += curr;
    cout << i << " => " << curr << endl;
  }
  cout << ans << endl;
  cout << endl;
  cout << endl;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long A, B; int K; cin >> A >> B >> K;

    cout << solve(K, B) - solve(K, A - 1) << endl;
  }
}
