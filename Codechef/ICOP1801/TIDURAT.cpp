#include <bits/stdc++.h>

using namespace std;

int N, M;
int T[200000 + 100], R[200000 + 100];
vector<pair<int, int>> A;
int P[200000 + 100];
int dp[21][200000 + 100];
int mx[200000 + 100];

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++) {
    scanf("%d %d", &T[i], &R[i]);
    A.push_back({T[i], R[i]});
  }

  sort(A.begin(), A.end());
  vector<int> heads;
  for(int i = 0; i < N; i++) {
    P[i] = -1;
    while(!heads.empty() && A[heads.back()].second < A[i].second) {
      P[heads.back()] = i;
      heads.pop_back();
    }
    heads.push_back(i);
  }

  for(int i = N - 1; i >= 0; i--) {
    if(P[i] == -1) mx[i] = 0;
    else mx[i] = mx[P[i]] + 1;
  }

  for(int i = 0; i < N; i++) {
    dp[0][i] = P[i];
  }

  for(int j = 1; j < 21; j++) {
    for(int i = 0; i < N; i++) {
      dp[j][i] = -1;
      if(dp[j - 1][i] != -1) dp[j][i] = dp[j - 1][dp[j - 1][i]];
    }
  }

  while(M--) {
    int i, p; scanf("%d %d", &i, &p); i--;
    int ind = lower_bound(A.begin(), A.end(), make_pair(T[i], R[i])) - A.begin();
    p = min(p, mx[ind]);

    int curr = ind;
    for(int j = 20; j >= 0; j--) {
      if(p & (1 << j)) curr = dp[j][curr];
    }

    printf("%d\n", A[curr].second);
  }
}
