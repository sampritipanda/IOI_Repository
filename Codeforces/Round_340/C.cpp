#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

vector<pair<long long, long long> > A;

long long dist(long long x1, long long y1, long long x2, long long y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int N; cin >> N;
  long long x1, y1; cin >> x1 >> y1;
  long long x2, y2; cin >> x2 >> y2;

  for(int i = 0; i < N; i++) {
    long long x, y; cin >> x >> y;
    A.push_back({x, y});
  }

  long long ans = LLONG_MAX;
  for(int i = 0; i < N; i++) {
    long long r1 = dist(A[i].first, A[i].second, x1, y1);
    long long r2 = 0;

    for(int j = 0; j < N; j++) {
      if(dist(x1, y1, A[j].first, A[j].second) > r1) {
        r2 = max(r2, dist(x2, y2, A[j].first, A[j].second));
      }
    }

    ans = min(ans, r1 + r2);
  }

  long long r2 = 0;
  for(int j = 0; j < N; j++) {
    r2 = max(r2, dist(x2, y2, A[j].first, A[j].second));
  }
  ans = min(ans, r2);

  cout << ans << endl;
}
