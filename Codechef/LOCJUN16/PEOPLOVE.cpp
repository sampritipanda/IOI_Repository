#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

pair<int, int> edges[1000001];
set<int> G[100001];
int D[100001];
vector<pair<int, int> > temp;
set<int> in[100001], out[100001];
stack<int> S;
bool vis[100001];

// j == outward, i = inward
void dfs(int i, int j) {
  if(vis[i]) return;
  vis[i] = true;

  while(G[i].size() > 0) {
    int cnt = 0;
    int u;
    if(rand() % 2 == 0) {
      u = *G[i].begin(); G[i].erase(G[i].begin());
    }
    else {
      u = *G[i].rbegin(); G[i].erase(u);
    }
    G[u].erase(i);
start:

    if(cnt < 2) {
      if(j == 0) {
        if(in[u].size() > out[u].size() || (cnt == 0 && out[i].size() > in[i].size())) {
          j = 1;
          cnt++;
          goto start;
        }
      }
      else {
        if(out[u].size() > in[u].size() || (cnt == 0 && in[i].size() > out[i].size())) {
          j = 0;
          cnt++;
          goto start;
        }
      }
    }

    if(j == 0) {
      out[i].insert(u);
      in[u].insert(i);
      dfs(u, j);
      j = 1;
    }
    else {
      in[i].insert(u);
      out[u].insert(i);
      dfs(u, j);
      j = 0;
    }
  }
}

int main() {
  int T; scanf("%d", &T);
  // printf("BOTH_SUBTASKS\n");

  while(T--) {
    int N, M; scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
      G[i].clear();
      D[i] = 0;
      in[i].clear(); out[i].clear();
      vis[i] = false;
    }
    temp.clear();

    for(int i = 1; i <= M; i++) {
      int u, v; scanf("%d %d", &u, &v);
      G[u].insert(v);
      G[v].insert(u);
      D[u]++;
      D[v]++;
      edges[i] = {u, v};
    }

    for(int i = 1; i <= N; i++) {
      temp.push_back({D[i], i});
    }
    sort(temp.begin(), temp.end());

    while(!S.empty()) S.pop();
    for(int i = 0; i < N; i++) S.push(temp[i].second);

    while(!S.empty()) {
      int u = S.top(); S.pop();
      if(G[u].size() == 0) continue;

      vector<pair<int, int> > temp_2;
      for(int v: G[u]) {
        if(in[u].size() < out[u].size()) {
          in[u].insert(v);
          out[v].insert(u);
          G[v].erase(u);
        }
        else if(in[u].size() > out[u].size()){
          out[u].insert(v);
          in[v].insert(u);
          G[v].erase(u);
        }
        else {
          if(out[v].size() < in[v].size()) {
            in[u].insert(v);
            out[v].insert(u);
            G[v].erase(u);
          }
          else {
            out[u].insert(v);
            in[v].insert(u);
            G[v].erase(u);
          }
        }
        temp_2.push_back({G[v].size(), v});
      }
      sort(temp_2.begin(), temp_2.end());
      for(auto it: temp_2) S.push(it.second);
      G[u].clear();
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
      ans = max(ans, (int)abs(int(in[i].size()) - int(out[i].size())));
    }
    if(ans == 0) {
      printf("%d\n", ans);
      for(int i = 1; i <= M; i++) {
        int u = edges[i].first, v = edges[i].second;
        if(out[u].count(v) > 0) {
          printf("%d %d\n", u, v);
        }
        else if(out[v].count(u) > 0) {
          printf("%d %d\n", v, u);
        }
        else {
          assert(false);
        }
      }
    }
    else {
      for(int iters = 0; iters <= 5; iters++) {
        if(ans > 1) {
          for(int i = 1; i <= N; i++) {
            for(int x: in[i]) G[i].insert(x);
            for(int x: out[i]) G[i].insert(x);
            in[i].clear();
            out[i].clear();
            vis[i] = false;
          }

          for(int i = 1; i <= N; i++) {
            if(vis[i]) continue;
            dfs(i, 0);
          }
        }
        else break;

        ans = 0;
        for(int i = 1; i <= N; i++) {
          ans = max(ans, (int)abs(int(in[i].size()) - int(out[i].size())));
        }
      }

      if(ans > 1) {
        for(int i = 1; i <= N; i++) {
          for(int x: in[i]) G[i].insert(x);
          for(int x: out[i]) G[i].insert(x);
          in[i].clear();
          out[i].clear();
          vis[i] = false;
        }

        reverse(temp.begin(), temp.end());

        for(int j = 0; j < N; j++) {
          int i = temp[i].second;
          if(vis[i]) continue;
          dfs(i, 0);
        }
      }

      ans = 0;
      for(int i = 1; i <= N; i++) {
        ans = max(ans, (int)abs(int(in[i].size()) - int(out[i].size())));
      }
      assert(ans <= 1);
      printf("%d\n", ans);

      for(int i = 1; i <= M; i++) {
        int u = edges[i].first, v = edges[i].second;
        if(out[u].count(v) > 0) {
          printf("%d %d\n", u, v);
        }
        else if(out[v].count(u) > 0) {
          printf("%d %d\n", v, u);
        }
        else {
          assert(false);
        }
      }
    }
  }
}
