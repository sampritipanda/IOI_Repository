#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

set<int> G[100001];
int D[100001];
bool improve[100001];

vector<int> make_vector(int a, int b, int c, int d) {
  vector<int> A;
  A.push_back(a);
  A.push_back(b);
  A.push_back(c);
  A.push_back(d);
  return A;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K, a, b; cin >> N >> M >> K >> a >> b;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
  }

  for(int i = 1; i <= N; i++) {
    D[i] = INT_MAX/2;
  }

  set<vector<int> > Q;  // {d, u, t, p}
  D[K] = 0;
  Q.insert(make_vector(D[K], K, 1, 0));

  while(!Q.empty()) {
    vector<int> curr = *Q.begin(); Q.erase(Q.begin());
    int d = curr[0], u = curr[1], t = curr[2], p = curr[3];

    improve[u] = false;
    for(set<int>::iterator _ = G[u].begin(); _ != G[u].end(); _++) {
      int v = *_;
      if(t == 0 && G[p].count(v) == 0 && D[p] + b < D[v]) {
        if(D[v] != INT_MAX/2) {
          set<vector<int> >::iterator it = Q.lower_bound(make_vector(D[v], v, 1, 0));
          if(it != Q.end() && (*it)[0] == D[v] && (*it)[1] == v && (*it)[2] == 1) Q.erase(it);
        }
        D[v] = D[p] + b;
        improve[u] = true;
        Q.insert(make_vector(D[v], v, 1, u));
      }
      if(D[u] + a < D[v]) {
        D[v] = D[u] + a;
        Q.insert(make_vector(D[v], v, 0, u));
      }
      else if (t == 1) {
        if(v == p && !improve[v]) continue;
        // high priority
        Q.insert(make_vector(INT_MIN/2, v, 0, u));
      }
    }
  }
  for(int i = 1; i <= N; i++) cout << D[i] << endl;
}
