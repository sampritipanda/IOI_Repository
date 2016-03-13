#include <iostream>
#include <algorithm>

using namespace std;

long long A[200001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  long long change_now = A[1] * 1 - A[2], start_now = 1;
  long long max_change = max(0LL, change_now);
  for(int i = 3; i <= N; i++) {
    change_now = change_now + A[start_now] - A[i];
    if(A[i - 1] - A[i] > change_now) {
      change_now = A[i - 1] - A[i];
      start_now = i - 1;
    }
    max_change = max(max_change, change_now);
  }

  change_now = -A[N] + A[N - 1], start_now = N;
  for(int i = N - 2; i >= 1; i--) {
    change_now = change_now + A[i] - A[start_now];
    if(-A[i + 1] + A[i] > change_now) {
      change_now = -A[i + 1] + A[i];
      start_now = i + 1;
    }
    max_change = max(max_change, change_now);
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans += A[i] * i;
  ans = max(ans, ans + max_change);
  cout << ans << endl;
}
