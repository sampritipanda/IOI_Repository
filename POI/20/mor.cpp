#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> G[5001];
short D[5001][5001][2];
queue<pair<int, short> > Q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      D[i][j][0] = D[i][j][1] = SHRT_MAX/2;
    }

    Q.push(make_pair(i, 0));
    while(!Q.empty()) {
      int u = Q.front().first;
      short d = Q.front().second;
      Q.pop();

      if(d >= D[i][u][d % 2]) continue;
      D[i][u][d % 2] = d;

      for(int j = 0; j < G[u].size(); j++) {
        Q.push(make_pair(G[u][j], d + 1));
      }
    }
  }

  while(K--) {
    int s, t, d; cin >> s >> t >> d;

    if(s == t && G[s].size() == 0) cout << "NIE" << endl;
    else if(D[s][t][d % 2] != SHRT_MAX/2 && d >= D[s][t][d % 2]) cout << "TAK" << endl;
    else cout << "NIE" << endl;
  }
}
