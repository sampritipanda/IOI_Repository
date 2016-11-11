#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, S; cin >> N >> S;
  bool inserted = false;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A.push_back(x);
  }
  sort(A.begin(), A.end());

  if(N == 1) {
    cout << 0 << endl;
    return 0;
  }

  A.insert(upper_bound(A.begin(), A.end(), S), S);

  int pos = lower_bound(A.begin(), A.end(), S) - A.begin();

  int ans = INT_MAX/2;
  for(int i = pos - 1; i >= 0; i--) {
    int used = pos - i;
    if(used == N - 1) {
      ans = min(ans, S - A[i]);
      break;
    }
    else {
      int left = (N - 1) - used;

      if(pos + left < N + 1) {
        ans = min(ans, S - A[i] + A[pos + left] - A[i]);
      }
    }
  }

  for(int i = pos + 1; i < N + 1; i++) {
    int used = i - pos;
    int left = (N - 1) - used;
    if(used == N - 1) {
      ans = min(ans, A[i] - S);
      break;
    }
    else {
      int left = (N - 1) - used;

      if(pos - left >= 0) {
        ans = min(ans, A[i] - S + A[i] - A[pos - left]);
      }
    }
  }

  cout << ans << endl;
}
