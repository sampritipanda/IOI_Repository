#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  // freopen("angry.in", "r", stdin);
  // freopen("angry.out", "w", stdout);

  int N; cin >> N;
  vector<int> A(N);

  for(int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());

  int ans = 0;
  for(int s = 0; s < N; s++) {
    int i = s, j = s;
    int t = 1;
    while(true) {
      bool changed = false;

      int k;
      for(k = i - 1; k >= 0; k--) {
        if(A[i] - A[k] > t) break;
      }
      k++;
      if(k < i) {
        i = k;
        changed = true;
      }

      for(k = j + 1; k < N; k++) {
        if(A[k] - A[j] > t) break;
      }
      k--;
      if(k > j) {
        j = k;
        changed = true;
      }

      if(!changed) break;
      t++;
    }

    ans = max(ans, j - i + 1);
  }

  cout << ans << endl;
}
