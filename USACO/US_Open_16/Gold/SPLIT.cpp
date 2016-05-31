#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

long long X[50001];
long long Y[50001];
vector<pair<long long, int> > X_set, Y_set;

int main() {
  freopen("split.in", "r", stdin);
  freopen("split.out", "w", stdout);

  int N; cin >> N;

  long long min_x = LLONG_MAX, max_x = 0;
  long long min_y = LLONG_MAX, max_y = 0;

  for(int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];

    min_x = min(min_x, X[i]);
    max_x = max(max_x, X[i]);

    min_y = min(min_y, Y[i]);
    max_y = max(max_y, Y[i]);

    X_set.push_back({X[i], i});
    Y_set.push_back({Y[i], i});
  }

  sort(X_set.begin(), X_set.end());
  sort(Y_set.begin(), Y_set.end());

  long long orig = (max_x - min_x) * (max_y - min_y);
  long long ans = 0;

  multiset<long long> left, right;

  for(int i = 1; i <= N; i++) right.insert(Y[i]);
  for(int i = 0; i < N - 1; i++) {
    left.insert(Y[X_set[i].second]);
    right.erase(right.find(Y[X_set[i].second]));
    long long new_size = (X_set[i].first - min_x) * (*left.rbegin() - *left.begin()) + (max_x - X_set[i + 1].first) * (*right.rbegin() - *right.begin());
    ans = max(ans, orig - new_size);
  }
  left.clear(); right.clear();

  for(int i = 1; i <= N; i++) right.insert(X[i]);
  for(int i = 0; i < N - 1; i++) {
    left.insert(X[Y_set[i].second]);
    right.erase(right.find(X[Y_set[i].second]));
    long long new_size = (Y_set[i].first - min_y) * (*left.rbegin() - *left.begin()) + (max_y - Y_set[i + 1].first) * (*right.rbegin() - *right.begin());
    ans = max(ans, orig - new_size);
  }
  left.clear(); right.clear();


  cout << ans << endl;
}
