#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<pair<int, int> > A;
map<int, vector<int> > X, Y;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  A.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    X[A[i].first].push_back(A[i].second);
    Y[A[i].second].push_back(A[i].first);
  }

  for(auto& it: X) {
    sort(it.second.begin(), it.second.end());
  }
  for(auto& it: Y) {
    sort(it.second.begin(), it.second.end());
  }

  long long ans = 0;

  for(int i = 0; i < N; i++) {
    int x = A[i].first, y = A[i].second;

    int top = X[x].end() - upper_bound(X[x].begin(), X[x].end(), y);
    int bot = lower_bound(X[x].begin(), X[x].end(), y) - X[x].begin();

    int right = Y[y].end() - upper_bound(Y[y].begin(), Y[y].end(), x);
    int left = lower_bound(Y[y].begin(), Y[y].end(), x) - Y[y].begin();

    ans += 1LL * top * bot * left * right * 2;
  }

  cout << ans << endl;
}
