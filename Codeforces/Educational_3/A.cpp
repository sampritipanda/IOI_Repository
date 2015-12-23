#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  int cnt = 0;
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  for(int i = 0; i < N; i++) {
    if(M == 0) break;

    if(M < A[i]) {
      cnt += 1;
      M = 0;
    }
    else {
      cnt += 1;
      M -= A[i];
    }
  }

  cout << cnt << endl;
}
