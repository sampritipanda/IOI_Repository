#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(vector<int> A) {
  int N = 4;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(A[i] == A[j]) {
        for(int k = i; k <= j; k++) {
          if(A[k] != A[i]) return false;
        }
      }
    }
  }

  return true;
}

int main() {
  int K; cin >> K;

  int ans = 0;

  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int k = 1; k <= K; k++) {
        for(int l = 1; l <= K; l++) {
          if(check({i, j, k, l})) ans++;
        }
      }
    }
  }

  cout << ans << endl;
}
