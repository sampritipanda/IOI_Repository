#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[101];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    for(int i = 1; i <= N; i++) cin >> A[i];

    int ans = 0;
    for(int i = 1; i <= N; i++) {
      if(A[i] == i) continue;
      int cnt = 0;
      for(int j = 1; j <= N; j++) {
        if(A[j] == i) cnt++;
      }
      if(cnt >= K) ans++;
    }
    cout << ans << endl;
  }
}
