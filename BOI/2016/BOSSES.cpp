#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

vector<int> G[5001];
int D[5001];
int curr_ans;
queue<pair<int, int> > Q;

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    int K; scanf("%d", &K);

    while(K--) {
      int x; scanf("%d", &x);
      G[x].push_back(i);
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i <= N; i++) {
    memset(D, 0, sizeof D);

    Q.push({i, 0});
    while(!Q.empty()) {
      int u = Q.front().first, p = Q.front().second; Q.pop();
      if(D[u]) continue;
      D[u] = D[p] + 1;

      for(int v: G[u]) {
        if(D[v]) continue;
        Q.push({v, u});
      }
    }

    bool valid = true;
    for(int j = 1; j <= N; j++) {
      if(!D[j]) {
        valid = false;
        break;
      }
    }
    if(!valid) continue;

    int curr_ans = 0;
    for(int j = 1; j <= N; j++) curr_ans += D[j];
    ans = min(ans, curr_ans);
  }

  printf("%d\n", ans);
}
