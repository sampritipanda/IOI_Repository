#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cassert>
#include <bitset>

using namespace std;

vector<int> G[1000001];
int C[1000001];
int D[1000001];
bitset<1000001> vis, vis2;
stack<int> S;

struct degree_compare {
  bool operator() (const int L, const int R) const {
    if(D[L] == D[R]) return L < R;
    return D[L] < D[R];
  }
};

struct degree_compare_rev {
  bool operator() (const int L, const int R) const {
    if(D[L] == D[R]) return L > R;
    return D[L] > D[R];
  }
};


set<int, degree_compare> comp;
priority_queue<int, vector<int>, degree_compare_rev> curr;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);

    D[u]++; D[v]++;
  }

  int timer = 0;

  for(int i = 1; i <= N; i++) {
    if(vis2[i]) continue;

    S.push(i);
    while(!S.empty()) {
      int u = S.top(); S.pop();
      if(vis2[u]) continue;
      vis2[u] = 1;
      comp.insert(u);

      for(int v: G[u]) S.push(v);
    }

    if(comp.size() < K) {
      comp.clear();
      continue;
    }

    while(comp.size() % K > 0) {
      int min_u = *comp.begin();
      for(int v: G[min_u]) {
        if(vis[v]) continue;
        comp.erase(v);
        D[v]--;
        comp.insert(v);
      }
      vis[min_u] = 1;
      comp.erase(min_u);
      D[min_u] = 0;
    }

    while(comp.size() > 0) {
      ++timer;
      while(!curr.empty()) curr.pop();
      int min_u = *comp.begin();
      curr.push(min_u);

      for(int t = 0; t < K; t++) {
        min_u = curr.top(); curr.pop();
        comp.erase(min_u);
        C[min_u] = timer;
        for(int v: G[min_u]) {
          if(vis[v]) continue;
          curr.push(v);
        }
        vis[min_u] = 1;
      }
    }
  }

  int ans1 = 0, ans2 = 0;
  for(int i = 1; i <= N; i++) {
    if(C[i]) ans1++;

    for(int u: G[i]) {
      if(C[u] != C[i]) {
        ans2++;
      }
    }
  }
  ans2 /= 2;

  cout << ans1 << " " << ans2 << endl;
}
