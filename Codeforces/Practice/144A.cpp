#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  int a = *min_element(A.begin(), A.end()), b = *max_element(A.begin(), A.end());
  int b_ind;
  for(int i = 0; i < N; i++) {
    if(A[i] == b) {
      b_ind = i;
      break;
    }
  }

  int ans = 0;
  ans += b_ind;

  A.erase(A.begin() + b_ind);
  A.insert(A.begin(), b);

  int a_ind;
  for(int i = N - 1; i >= 0; i--) {
    if(A[i] == a) {
      a_ind = i; break;
    }
  }

  ans += (N - 1) - a_ind;

  cout << ans << endl;
}
