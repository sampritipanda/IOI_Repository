#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long A[2001], B[2001];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int M; cin >> M;
  for(int i = 1; i <= M; i++) cin >> B[i];

  long long sum_a = 0, sum_b = 0;
  for(int i = 1; i <= N; i++) sum_a += A[i];
  for(int i = 1; i <= M; i++) sum_b += B[i];

  int K = 0; vector<pair<int, int> > ans; long long v = abs(sum_a - sum_b);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(abs(sum_a - sum_b + 2 * (B[j] - A[i])) < v) {
        v = abs(sum_a - sum_b + 2 * (B[j] - A[i]));
        K = 1;
        ans = {{i, j}};
      }
    }
  }

  vector<pair<long long, pair<int, int> > > X, Y;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i == j) continue;
      X.push_back({A[i] + A[j], {i, j}});
    }
  }
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= M; j++) {
      if(i == j) continue;
      Y.push_back({B[i] + B[j], {i, j}});
    }
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  for(auto it: X) {
    long long val = it.first;
    long long req = (0 - (sum_a - sum_b - 2 * val))/2;
    auto it2 = lower_bound(Y.begin(), Y.end(), make_pair(req, make_pair(0, 0)));
    if(it2 != Y.end()) {
      if(abs(sum_a - sum_b - 2 * val + 2 * it2->first) < v) {
        v = abs(sum_a - sum_b - 2 * val + 2 * it2->first);
        K = 2;
        ans = {{it.second.first, it2->second.first}, {it.second.second, it2->second.second}};
      }
    }
    if(it2 != Y.begin()) {
      it2--;
      if(abs(sum_a - sum_b - 2 * val + 2 * it2->first) < v) {
        v = abs(sum_a - sum_b - 2 * val + 2 * it2->first);
        K = 2;
        ans = {{it.second.first, it2->second.first}, {it.second.second, it2->second.second}};
      }
    }
  }

  cout << v << endl;
  cout << K << endl;
  for(auto it: ans) cout << it.first << " " << it.second << endl;
}

// sum_a - sum_b + 2 * (B[j1] + B[j2]) - 2 * (A[i1] + A[i2])
