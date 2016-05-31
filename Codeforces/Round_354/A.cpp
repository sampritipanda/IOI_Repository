#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int A[101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j++) {
      swap(A[i], A[j]);

      int min_pos = -1, max_pos = -1;
      for(int k = 1; k <= N; k++) {
        if(A[k] == 1) min_pos = k;
        if(A[k] == N) max_pos = k;
      }
      ans = max(ans, abs(max_pos - min_pos));

      swap(A[i], A[j]);
    }
  }

  cout << ans << endl;
}
