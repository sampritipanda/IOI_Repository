// Random Number Generator

#include <iostream>
#include <vector>

using namespace std;

#define MOD 104857601ULL

typedef vector<vector<unsigned long long> > matrix;
int k; unsigned long long N; 

matrix mul(matrix A, matrix B){
  matrix C(k + 1, vector<unsigned long long>(k + 1));
  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= k; j++){
      for(int l = 1; l <= k; l++){
        C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % MOD;
      }
    }
  }

  return C;
}

matrix pow(matrix A, unsigned long long P){
  if(P == 1ULL) return A;
  if(P % 2) mul(A, pow(A, P - 1));
  matrix X = pow(A, P/2);
  return mul(X, X);
}

int main() {
  cin >> k >> N;
  int A[k], C[k];
  for(int i = 0; i < k; i++) cin >> A[i];
  for(int i = 0; i < k; i++) cin >> C[i];

  vector<unsigned long long> F1(k + 1);
  for(int i = 0; i < k; i++) F1[i + 1] = A[i];

  matrix T(k + 1, vector<unsigned long long>(k + 1));
  for(int i = 1; i < k; i++){
    for(int j = 1; j <= k; j++){
      T[i][j] = 0;
      if(j == i + 1) T[i][j] = 1;
    }
  }
  for(int i = k; i >= 1; i--) T[k][i] = C[k - i];

  if(N == 1ULL) cout << 1 << endl;
  else {
    T = pow(T, N - 1);
    unsigned long long res = 0;
    for(int i = 0; i <= k; i++) res = (res + T[1][i] * F1[i]) % MOD;
    cout << res << endl;
  }
}
