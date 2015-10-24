// Misha and Gym 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;
vector<int> dp;

int main() {
  int N, Q; cin >> N >> Q;

  A.resize(N + 1, 0);
  for(int i = 1; i <= N; i++) cin >> A[i];

  while(Q--) {
    int type; cin >> type;

    if(type == 1) {
      int i, X; cin >> i >> X;
      A[i] = X;
    }
    else if(type == 2) {
      int L, R; cin >> L >> R;
      reverse(A.begin() + L, A.begin() + 1 + R);
    }
    else {
      int L, R, W; cin >> L >> R >> W;
      dp.resize(W + 1);
      for(int i = 0; i <= W; i++) dp[i] = 0;

      dp[0] = 1;
      for(int i = L; i <= R; i++) {
        for(int j = W; j >= A[i]; j--) {
          dp[j] |= dp[j - A[i]];
        }
      }

      cout << (dp[W] ? "Yes" : "No") << endl;
    }
  }
}
