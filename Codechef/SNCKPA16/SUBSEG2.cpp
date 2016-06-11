#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int MAX_LOG = 17;
const int MAX = 100000;

vector<pair<int, int> > temp;
vector<pair<int, int> > A;
int dp[MAX_LOG][MAX + 2];

bool compare(pair<int, int> A, pair<int, int> B) {
  if(A.second == B.second) return A.first < B.first;
  return A.second < B.second;
}

bool compare2(pair<int, int> A, pair<int, int> B) {
  if(A.first == B.first) return A.second < B.second;
  return A.first < B.first;
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    int L, R; scanf("%d %d", &L, &R);
    temp.push_back({L, R});
  }
  sort(temp.begin(), temp.end(), compare);

  A.push_back(temp[0]);
  for(int i = 1; i < N; i++) {
    if(temp[i].second == A.back().second) {
      A.pop_back();
      A.push_back(temp[i]);
    }
    else {
      if(temp[i].first <= A.back().first) continue;
      A.push_back(temp[i]);
    }
  }
  N = A.size();
  A.push_back({INT_MAX/2, INT_MAX/2});

  set<pair<int, int> > b_set; b_set.insert({A[N].first, N});
  dp[0][N] = -1;
  for(int i = N - 1; i >= 0; i--) {
    dp[0][i] = b_set.lower_bound({A[i].second + 1, -1})->second;
    b_set.insert({A[i].first, i});
  }
  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 0; i <= N; i++) {
      dp[j][i] = -1;
      if(dp[j - 1][i] != -1)
        dp[j][i] = dp[j - 1][dp[j - 1][i]];
    }
  }

  while(Q--) {
    int L, R; scanf("%d %d", &L, &R);

    int ans = 0;
    int curr = lower_bound(A.begin(), A.end(), make_pair(L, L), compare2) - A.begin();
    if(curr < N && A[curr].second <= R) ans++;
    for(int j = MAX_LOG - 1; j >= 0; j--) {
      if(dp[j][curr] != -1 && A[dp[j][curr]].second <= R) {
        ans += (1 << j);
        curr = dp[j][curr];
      }
    }
    printf("%d\n", ans);
  }
}
