#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int D[1000001];
int sz[1000001];
int Q_K[1000001];
vector<int> G[1000001];
queue<pair<int, int> > DQ;

void dfs(int i) {
  D[i] = 1;
  sz[i] = 1;

  for(int j = 0; j < G[i].size(); j++) {
    int u = G[i][j];
    dfs(u);
    D[i] = max(D[i], 1 + D[u]);
    sz[i] += sz[u];
  }
}

bool compare(int L, int R) {
  return D[L] > D[R];
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  for(int i = 1; i <= Q; i++) scanf("%d", &Q_K[i]);

  for(int i = 2; i <= N; i++) {
    int p; scanf("%d", &p);
    G[p].push_back(i);
  }

  dfs(1);

  for(int i = 1; i <= N; i++) {
    sort(G[i].begin(), G[i].end(), compare);
  }

  for(int q = 1; q <= Q; q++) {
    int K = Q_K[q];
    int cnt = 1;
    DQ.push(make_pair(1, 1));
    int time = 1;

    while(!DQ.empty()) {
      pair<int, int> it = DQ.front(); DQ.pop();
      int curr_time = it.second, u = it.first;

      if(curr_time == time) {
        time++;
        cnt = 0;
      }

      for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];
        DQ.push(make_pair(v, time));
        cnt++;

        if(cnt == K) {
          cnt = 0;
          time++;
        }
      }
    }

    if(cnt == 0) time--;

    printf("%d", time);
    if(q == Q) printf("\n");
    else printf(" ");
  }
}
