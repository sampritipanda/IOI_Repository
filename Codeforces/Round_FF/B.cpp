#include <iostream>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

int A[1001][1001];
long long R[1001];
long long C[1001];
long long R_best[1000001], C_best[1000001];
set<pair<long long, int> > R_Q, C_Q;   // {val, id}

int main() {
  int N, M, K; long long P; cin >> N >> M >> K >> P;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
      R[i] += A[i][j];
      C[j] += A[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    R_Q.insert({R[i], i});
  }
  R_best[0] = 0;
  for(int i = 1; i <= K; i++) {
    long long val = R_Q.rbegin()->first; int id = R_Q.rbegin()->second;
    R_Q.erase(*R_Q.rbegin());
    R_best[i] = val + R_best[i - 1];
    val -= M * P;
    R_Q.insert({val, id});
  }

  for(int i = 1; i <= M; i++) {
    C_Q.insert({C[i], i});
  }
  C_best[0] = 0;
  for(int i = 1; i <= K; i++) {
    long long val = C_Q.rbegin()->first; int id = C_Q.rbegin()->second;
    C_Q.erase(*C_Q.rbegin());
    C_best[i] = val + C_best[i - 1];
    val -= N * P;
    C_Q.insert({val, id});
  }

  long long ans = LLONG_MIN;
  for(int row_cnt = 0; row_cnt <= K; row_cnt++) {
    int col_cnt = K - row_cnt;
    ans = max(ans, R_best[row_cnt] + C_best[col_cnt] - P * row_cnt * col_cnt);
  }
  cout << ans << endl;
}
