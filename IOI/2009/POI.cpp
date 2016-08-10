#include <iostream>
#include <algorithm>

using namespace std;

int A[2000][2000];
int T_S[2000];
int S[2000];
int C[2000];

int main() {
  int N, T, P; cin >> N >> T >> P; P--;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < T; j++) {
      cin >> A[i][j];
      if(A[i][j]) {
        C[i]++;
      }
      else {
        T_S[j]++;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < T; j++) {
      if(A[i][j]) S[i] += T_S[j];
    }
  }

  int cnt = 0;

  for(int i = 0; i < N; i++) {
    if(i == P) continue;

    if(S[i] > S[P]) cnt++;
    else if(S[i] == S[P] && C[i] > C[P]) cnt++;
    else if(S[i] == S[P] && C[i] == C[P] && i < P) cnt++;
  }

  cout << S[P] << " " << cnt + 1 << endl;
}
