#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int> > R, C;   // color, time

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;
  R.resize(N + 1); C.resize(M + 1);

  for(int time = 1; time <= K; time++) {
    int T; cin >> T;

    if(T == 1) {
      int r, A; cin >> r >> A;
      R[r] = {A, time};
    }
    else {
      int c, A; cin >> c >> A;
      C[c] = {A, time};
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(R[i].second > C[j].second) {
        cout << R[i].first;
      }
      else {
        cout << C[j].first;
      }
      cout << " ";
    }
    cout << endl;
  }
}
