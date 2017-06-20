#include <iostream>
#include <algorithm>

using namespace std;

int A[1001][1001];
vector<vector<int> > visited;
vector<int> ans;
int vis[1001][1001][2];
int N;

int get_nxt(int i, int dir) {
  if(dir == 0) {
    return (i == N ? 1 : (i + 1));
  }
  else {
    return (i == 1 ? N : (i - 1));
  }
}

bool solve(int i, int end, int dir) {
  if(i == end) {
    ans.push_back(i);
    return 1;
  }
  if(vis[i][end][dir]) return false;
  visited.push_back({i, end, dir});
  vis[i][end][dir] = 1;

  int nxt = get_nxt(i, dir);
  if(A[i][nxt] && solve(nxt, end, dir)) {
    ans.push_back(i);
    return 1;
  }
  if(A[i][end] && solve(end, nxt, dir ^ 1)) {
    ans.push_back(i);
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M; cin >> N >> M;

  while(M--) {
    int u, v; cin >> u >> v;
    A[u][v] = 1;
    A[v][u] = 1;
  }

  bool done = false;

  for(int start = 1; start <= N; start++) {
    int end = get_nxt(start, 1);
    if(solve(start, end, 0)) {
      reverse(ans.begin(), ans.end());
      for(int x: ans) cout << x << endl;
      done = true;
      break;
    }
    else {
      for(auto it: visited) {
        vis[it[0]][it[1]][it[2]] = 0;
      }
      visited.clear();
    }
  }

  if(!done) cout << -1 << endl;
}
