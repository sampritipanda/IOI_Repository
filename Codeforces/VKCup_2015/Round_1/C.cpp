#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int N, k; cin >> N >> k;
  int A[N];
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  int Q; cin >> Q;
  while(Q--){
    int x; cin >> x;
    int ans = INT_MAX;
    for(int i = N - 1; i >= 0; i--) {
      for(int j = 1; j <= (x/A[i]); j++){
        int curr = x % A[i];;
        int count = j;
        if(count > k) continue;
        if(curr == 0) {
          ans = min(ans, count);
          continue;
        }
        for(int l = 1; l <= (k - j); l++){
          if(curr % l != 0) continue;
          if(binary_search(A, A + i, curr/j)){
            ans = min(ans, count + j);
            break;
          }
        }
      }
    }
    if(ans == INT_MAX || ans > k) ans = -1;
    cout << ans << endl;
  }
}
