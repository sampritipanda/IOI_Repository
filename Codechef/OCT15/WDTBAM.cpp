// Who dares to be a millionaire

#include <iostream>
#include <algorithm>

using namespace std;

int W[1000 + 1];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int correct = 0, incorrect = 0;
    string A, B; cin >> A >> B;
    for(int i = 0; i < N; i++) {
      if(A[i] == B[i]) correct++;
      else incorrect++;
    }

    for(int i = 0; i < N + 1; i++) cin >> W[i];
    int ans = 0;
    for(int i = 0; i < N + 1; i++) {
      if(i < correct && incorrect >= 1) ans = max(ans, W[i]);
      else if(i == correct) ans = max(ans, W[i]);
    }
    cout << ans << endl;
  }
}
