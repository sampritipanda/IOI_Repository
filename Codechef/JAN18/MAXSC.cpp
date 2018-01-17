#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A[700][700];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cin >> A[i][j];
      }
      sort(A[i], A[i] + N);
    }

    long long ans = 0;
    bool pos = true;
    int curr = INT_MAX/2;

    for(int i = N - 1; i >= 0; i--) {
      int* req = lower_bound(A[i], A[i] + N, curr) - 1;
      if(req < A[i]) {
        pos = false;
        break;
      }
      ans += *req;
      curr = *req;
    }

    if(pos) cout << ans << endl;
    else cout << -1 << endl;
  }
}
