#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int> > A, B;

bool compare(pair<int, int> L, pair<int, int> R) {
  if(L.second == R.second) return L.first < R.first;
  return L.second < R.second;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  A.resize(M);
  for(int i = 0; i < M; i++) {
    int r, c; scanf("%d %d", &A[i].first, &A[i].second);
  }

  sort(A.begin(), A.end(), compare);

  int min_1 = INT_MAX/2;
  for(int i = 0; i < M; i++) {
    if(i == 0 || A[i].second != A[i - 1].second) {
      if(A[i].first - A[i].second < min_1) {
        B.push_back(A[i]);
        min_1 = min(min_1, A[i].first - A[i].second);
      }
    }
  }

  long long ans = 0;
  ans += (1LL * ((N + 1) - B[0].first) * ((N + 1) - B[0].first + 1))/2;

  min_1 = B[0].first - B[0].second;
  for(int i = 1; i < B.size(); i++) {
    ans += (1LL * ((N + 1) - B[i].first) * ((N + 1) - B[i].first + 1))/2;
    int i_y = B[i].second + min_1;
    if(i_y <= N) {
      ans -= (1LL * ((N + 1) - i_y) * ((N + 1) - i_y + 1))/2;
    }
    min_1 = min(min_1, B[i].first - B[i].second);
  }

  printf("%lld\n", ans);
}
