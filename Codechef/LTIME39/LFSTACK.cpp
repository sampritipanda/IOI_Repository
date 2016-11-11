#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > B;
vector<int> A, P;
vector<int> F;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    B.clear();
    A.clear();
    P.clear();
    F.clear();

    int N; cin >> N;

    A.resize(N);
    B.resize(N);
    P.resize(N);

    int M = 0;

    for(int i = 0; i < N; i++) {
      cin >> A[i];

      M += A[i];

      B[i].resize(A[i]);
      for(int j = 0; j < A[i]; j++) {
        cin >> B[i][j];
      }
    }

    F.resize(M);
    for(int i = 0; i < M; i++) cin >> F[i];
    reverse(F.begin(), F.end());

    bool pos = true;
    for(int i = 0; i < M; i++) {
      bool inc = false;
      for(int j = 0; j < N; j++) {
        if(P[j] == A[j]) continue;

        if(F[i] == B[j][P[j]]) {
          inc = true;
          P[j]++;
          break;
        }
      }
      if(!inc) {
        pos = false;
        break;
      }
    }
    if(pos) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
