#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool visited[2505];
long long dp[2505][100];
int N, K;

void dfs(int i, int K){
  if(visited[i]) return;

  visited[i] = true;
  for(auto v: graph[i]){
    if(!visited[v]) dp[i][K] += dp[v][K - 1];
  }
}

int main() {
  cin >> N >> K;
  for(int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) dp[i][1] = 1;
  for(int i = 2; i <= K; i++){
    for(int i = 0; i <= 2505; i++){
      visited[i] = false;
    }
    dfs(1, i);
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++){
    ans += dp[i][K];
  }
  cout << ans << endl;
}
