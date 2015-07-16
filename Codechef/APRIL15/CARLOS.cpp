// Inversion sorting

#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

set<int> connections[205];
set<int> graph[205];
bool visited[205];
int A[200005];
int dp[200005][205];
int precalc[200005][205];
int N, M;

void dfs(int curr, int start){
  if(visited[curr]) return;
  visited[curr] = true;

  if(curr != start) connections[start].insert(curr);
  for(auto v: graph[curr]){
    dfs(v, start);
  }
}

int solve(int i, int previous){
  if(i == N) return 0;

  if(dp[i][previous] != -1) return dp[i][previous];

  int next = 20000000;
  for(auto v: connections[A[i]]){
    if(v < previous) continue;
    next = min(next, 1 + solve(i + 1, v));
  }
  if(A[i] >= previous) next = min(next, solve(i + 1, A[i]));
  dp[i][previous] = next;
  return next;
}

int main() {
  int T; cin >> T;

  while(T--){
    for(int i = 0; i < 205; i++){
      graph[i].clear();
      connections[i].clear();
    }

    int K; cin >> M >> K >> N;
    for(int i = 0; i < K; i++){
      int x, y; cin >> x >> y;
      graph[x].insert(y);
      graph[y].insert(x);
    }

    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 1; i <= M; i++){
      for(int i = 0; i <= M; i++) visited[i] = false;
      dfs(i, i);
    }

    for(int i = 0; i <= M; i++){
      for(int j = 0; j <= M; j++){
        precalc[i][j] = -1;
        auto v = connections[i].lower_bound(j);
        if(v != connections[i].end()) precalc[i][j] = *v;
      }
    }

    for(int i = 0; i <= M; i++) dp[N][i] = 0;
    for(int i = N - 1; i >= 0; i--){
      for(int j = 0; j <= M; j++){
        dp[i][j] = 20000000;
        int v = precalc[A[i]][j];
        if(v != -1) dp[i][j] = min(dp[i][j], 1 + dp[i + 1][v]);
        if(A[i] >= j) dp[i][j] = min(dp[i][j], dp[i + 1][A[i]]);
      }
    }

    if(dp[0][0] == 20000000) dp[0][0] = -1;
    cout << dp[0][0] << endl;
  }
}

