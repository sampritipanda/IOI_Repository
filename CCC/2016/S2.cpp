#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, B;

int main() {
  int T; cin >> T;

  int N; cin >> N;
  A.resize(N);
  B.resize(N);

  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  if(T == 1) {
    int ans = 0;
    for(int i = 0; i < N; i++) {
      ans += max(A[i], B[i]);
    }
    cout << ans << endl;
  }
  else {
    int ans1 = 0, ans2 = 0;
    reverse(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
      ans1 += max(A[i], B[i]);
    }
    reverse(A.begin(), A.end());

    reverse(B.begin(), B.end());
    for(int i = 0; i < N; i++) {
      ans2 += max(A[i], B[i]);
    }

    cout << max(ans1, ans2) << endl;
  }
}
