#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> R[100001]; // R[i] = switches affecting room i
vector<pair<int, int> > G[100001];
int stat[100001];
int col[100001];
bool pos = true;

void dfs(int i, int c) {
  if(col[i] != -1) {
    if(c != col[i]) pos = false;
    return;
  }

  col[i] = c;
  for(auto it: G[i]) {
    int u = it.first, w = it.second;
    dfs(u, w ^ c);
    if(!pos) return;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) cin >> stat[i];

  for(int i = 1; i <= M; i++) {
    int num; cin >> num;
    while(num--) {
      int x; cin >> x;
      R[x].push_back(i);
    }
  }

  for(int i = 1; i <= N; i++) {
    int u = R[i][0], v = R[i][1], w = (stat[i] == 0 ? 1 : 0);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  for(int i = 1; i <= M; i++) col[i] = -1;

  for(int i = 1; i <= M; i++) {
    if(col[i] != -1) continue;

    dfs(i, 0);
    if(!pos) break;
  }

  if(pos) cout << "YES" << endl;
  else cout << "NO" << endl;
}
