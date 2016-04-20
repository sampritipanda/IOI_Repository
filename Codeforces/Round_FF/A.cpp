#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int A[100002];
int L[100002];
int R[100002];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) {
    if(A[i] > A[i - 1]) L[i] = L[i - 1] + 1;
    else L[i] = 1;
  }

  for(int i = N; i >= 1; i--) {
    if(A[i] < A[i + 1]) R[i] = R[i + 1] + 1;
    else R[i] = 1;
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans = max(ans, 1 + L[i - 1]);
    ans = max(ans, 1 + R[i + 1]);

    if(A[i + 1] - A[i - 1] >= 2) {
      ans = max(ans, L[i - 1] + 1 + R[i + 1]);
    }
  }

  cout << ans << endl;
}
