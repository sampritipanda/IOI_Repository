// Lazy Loading

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int ans = 0;
    int i = 0, j = N - 1;
    while(i <= j) {
      int sum = A[j];
      while(i < j && sum < 50) {
        sum += A[j];
        i++;
      }
      if(sum >= 50) ans++;
      j--;
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
