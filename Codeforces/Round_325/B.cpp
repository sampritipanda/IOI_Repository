#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int A[51][2], B[51];
int N;

int calc_A(int x) {
  int ans = 0;
  for(int i = 1; i < x; i++) {
    ans += A[i][0];
  }
  ans += B[x];
  for(int i = x; i < N; i++) {
    ans += A[i][1];
  }
  return ans;
}

int calc_B(int x) {
  int ans = 0;
  for(int i = N; i > x; i--) {
    ans += A[i - 1][1];
  }
  ans += B[x];
  for(int i = x; i > 1; i--) {
    ans += A[i - 1][0];
  }
  return ans;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N - 1; i++) cin >> A[i][0];
  for(int i = 1; i <= N - 1; i++) cin >> A[i][1];
  for(int i = 1; i <= N; i++) cin >> B[i];

  int ans = INT_MAX;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i == j) continue;
      ans = min(ans, calc_A(i) + calc_B(j));
    }
  }

  cout << ans << endl;
}
