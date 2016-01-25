#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
long long A[100000];
map<pair<int, int>, long long> M;

long long solve(int i, int j) {
  if(j == K) return 0;
  if(i >= N - 1) return LLONG_MAX/2;
  if(2*j > N - i) return LLONG_MAX/2;

  if(M.count({i, j}) > 0) return M[{i, j}];

  long long ans = LLONG_MAX/2;
  if(i < N - 1) ans = min(ans, solve(i + 2, j + 1) + A[i + 1] - A[i]);
  ans = min(ans, solve(i + 1, j));
  M[{i, j}] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    M.clear();

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];

    cout << solve(0, 0) << endl;
  }
}
