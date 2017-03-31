#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

string A[1000], B[1000];
map<string, vector<int> > group;
string ans[1000];

vector<int> G[2000];
int dfs_num[2000], dfs_low[2000];
bool on_stack[2000];
int scc[2000];
stack<int> S;
int timer = 0;

vector<int> G2[2000];
vector<int> topo;
bool vis[2000];

void add(int u, int v) {
  // (u | v) === (!u => v) === (!v => u)
  G[u ^ 1].push_back(v);
  G[v ^ 1].push_back(u);
}

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  S.push(i);
  on_stack[i] = true;

  for(auto u: G[i]) {
    if(!dfs_num[u]) {
      dfs(u);
    }

    if(on_stack[u]) {
      dfs_low[i] = min(dfs_low[i], dfs_low[u]);
    }
  }

  if(dfs_num[i] == dfs_low[i]) {
    while(true) {
      int v = S.top(); S.pop();
      on_stack[v] = false;
      scc[v] = i;
      if(v == i) break;
    }
  }
}

void dfs2(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(auto u: G2[i]) {
    dfs2(u);
  }

  topo.push_back(i);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    string X, Y; cin >> X >> Y;
    A[i] = X.substr(0, 3);
    B[i] = X.substr(0, 2) + Y.substr(0, 1);
  }

  bool pos = true;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(A[i] == A[j] && B[i] == B[j]) {
        pos = false;
        break;
      }
    }
    if(!pos) break;
  }

  if(pos) {
    for(int i = 0; i < N; i++) {
      group[A[i]].push_back(i);
    }

    for(auto it: group) {
      if(it.second.size() > 1) {
        for(int i: it.second) {
          ans[i] = B[i];
          add(2 * i, 2 * i);
        }
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = i + 1; j < N; j++) {
        int u = 2 * i, v = 2 * j;
        if(A[i] == B[i]) {
          add(u, v);
        }
        if(A[i] == B[j]) {
          add(u, v ^ 1);
        }
        if(B[i] == A[j]) {
          add(u ^ 1, v);
        }
        if(B[i] == B[j]) {
          add(u ^ 1, v ^ 1);
        }
      }
    }

    for(int i = 0; i < 2*N; i++) {
      if(dfs_num[i]) continue;
      dfs(i);
    }

    for(int i = 0; i < 2*N; i++) {
      for(auto u: G[i]) {
        G2[scc[i]].push_back(scc[u]);
      }
    }

    for(int i = 0; i < 2*N; i++) {
      if(vis[i]) continue;
      if(scc[i] != i) continue;
      dfs2(i);
    }
    reverse(topo.begin(), topo.end());

    for(int i = 0; i < N; i++) {
      int ind_1 = find(topo.begin(), topo.end(), scc[2*i]) - topo.begin();
      int ind_2 = find(topo.begin(), topo.end(), scc[2*i ^ 1]) - topo.begin();

      if(scc[2*i] == scc[2*i ^ 1]) {
        pos = false;
        break;
      }

      if(ind_1 < ind_2) {
        ans[i] = A[i];
      }
      else {
        ans[i] = B[i];
      }
    }


    for(int i = 0; i < N; i++) {
      if(!pos) break;
      for(int j = i + 1; j < N; j++) {
        if(ans[i] == ans[j]) {
          pos = false;
          break;
        }
      }
    }

    if(pos) {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) cout << ans[i] << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
}
