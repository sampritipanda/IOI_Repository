#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string S; cin >> S;

  int M; cin >> M;

  while(M--) {
    int L, R, K; cin >> L >> R >> K; L--; R--;
    int N = R - L + 1;
    K %= N;

    string T = S;
    for(int i = L + N - K; i <= R; i++) {
      T[i - (N - K)] = S[i];
    }
    for(int i = L; i <= R - K; i++) {
      T[i + K] = S[i];
    }

    S = T;
  }

  cout << S << endl;
}
