#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A[200001];
int ans[200001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    ans[i] = INT_MAX/2;
  }

  int zero_pos = INT_MIN/2;
  for(int i = 1; i <= N; i++) {
    if(A[i] == 0) zero_pos = i;
    ans[i] = min(ans[i], i - zero_pos);
  }

  zero_pos = INT_MAX/2;
  for(int i = N; i >= 1; i--) {
    if(A[i] == 0) zero_pos = i;
    ans[i] = min(ans[i], zero_pos - i);
  }

  for(int i = 1; i <= N; i++) cout << ans[i] << " "; cout << endl;
}
