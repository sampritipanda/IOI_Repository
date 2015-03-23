#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int N, k; cin >> N >> k;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  int Q; cin >> Q;
  while(Q--){
    int x; cin >> x;
    int ans = INT_MAX;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(i == j) continue;
        if(x % A[i] == 0){
          ans = min(ans, x/A[i]);
          break;
        }
        else {
          int rem = x % A[i];
          if(rem % A[j] == 0 && (x/A[i] + rem/A[j]) <= k){
            ans = min(ans, (x/A[i] + rem/A[j]));
          }
        }
      }
    }
    if(ans == INT_MAX || ans > k) ans = -1;
    cout << ans << endl;
  }
}
