// Ants

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long n;

vector<vector<long long> > _combine(vector<vector<long long> > A, vector<vector<long long> > B){
  vector<vector<long long> > R(n + 1, vector<long long>(n + 1));
  for(long long i = 1; i <= n; i++){
    for(long long j = 1; j <= n; j++){
      R[i][j] = LLONG_MIN;
      for(long long k = 1; k <= n; k++){
        if(A[i][k] != LLONG_MIN && B[k][j] != LLONG_MIN){
          R[i][j] = max(R[i][j], A[i][k] + B[k][j]);
        }
      }
    }
  }
  return R;
}

vector<vector<long long> > combine(vector<vector<long long> > M, long long x){
  if(x == 1) return M;
  if(x % 2 == 1) return _combine(M, combine(M, x - 1));

  vector<vector<long long> > P = combine(M, x/2);
  return _combine(P, P);
}

int main() {
  long long stepsPerSecond, timeLimit; cin >> n >> stepsPerSecond >> timeLimit;
  vector<vector<long long> > M(n + 1, vector<long long>(n + 1));

  for(long long i = 1; i <= n; i++) {
    for(long long j = 1; j <= n; j++) {
      cin >> M[i][j];
      if(M[i][j] == -999) M[i][j] = LLONG_MIN;
    }
  }

  M = combine(M, stepsPerSecond);

  for(int i = 1; i <= n; i++) {
    if(M[i][i] < 0) M[i][i] = 0;
  }

  M = combine(M, timeLimit);
  if(M[1][2] == LLONG_MIN) cout << "IMPOSSIBLE" << endl;
  else cout << M[1][2] << endl;
}
