#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

typedef vector<vector<long long> > matrix;

matrix multiply(matrix A, matrix B) {
  matrix C;
  int N = A.size(), M = B[0].size();

  for(int i = 0; i < N; i++) {
    C.push_back(vector<long long>(M));
    for(int j = 0; j < M; j++) {
      for(int k = 0; k < A[0].size(); k++) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] %= MOD;
      }
    }
  }

  return C;
}

matrix mat_pow(matrix A, long long exp) {
  if(exp == 1) return A;
  if(exp % 2 == 1) return multiply(mat_pow(A, exp - 1), A);

  matrix C = mat_pow(A, exp/2);
  return multiply(C, C);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long A, B, N, x; cin >> A >> B >> N >> x;

  cout << multiply({{x, 1}}, mat_pow({{A, 0}, {B, 1}}, N))[0][0] << endl;;
}
