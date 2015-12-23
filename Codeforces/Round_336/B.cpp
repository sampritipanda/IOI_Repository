#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string A, B;
int X[200001], Y[200001];

inline int pref(int i, int j, int k) {
  if(k == 0) {
    if(i == 0) return X[j];
    else return X[j] -  X[i - 1];
  }
  else {
    if(i == 0) return Y[j];
    else return Y[j] -  Y[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> A >> B;
  int N = A.length(), M = B.length();

  X[0] = (B[0] == '0' ? 1 : 0);
  Y[0] = (B[0] == '1' ? 1 : 0);
  for(int i = 1; i < M; i++) {
    X[i] = X[i - 1] + (B[i] == '0' ? 1 : 0);
    Y[i] = Y[i - 1] + (B[i] == '1' ? 1 : 0);
  }

  long long sum = 0;
  for(int i = 0; i < N; i++) {
    sum += pref(i, M - N + i, A[i] == '0' ? 1 : 0);
  }

  cout << sum << endl;
}

