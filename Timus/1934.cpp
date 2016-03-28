// P(A) = A
// P(B) = B
// P(A | B) = P(A) + P(B) - (P(A) * P(B))
// P(A | B | C) = P(A | B) + P(C) - (P(A | B) * P(C))
//              = P(A) + P(B) + P(C) - P(A) * P(B) - P(A) * P(C) - P(B) * P(C) + P(A) * P(B) * P(C)


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

vector<pair<int, double> > G[100001];
set<pair<pair<int, double>, int> > Q;  // { {dist, probablity,}, vertex
int D[100001];
double P[100001];
int par[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  int s, t; cin >> s >> t;

  while(M--) {
    int a, b, p; cin >> a >> b >> p;
    G[a].push_back({b, p/100.0});
    G[b].push_back({a, p/100.0});
  }

  for(int i = 0; i <= N; i++) {
    D[i] = INT_MAX/2;
    P[i] = -1;
    par[i] = -1;
  }

  Q.insert({{1, 0}, s});
  D[s] = 1;
  P[s] = 0;

  while(!Q.empty()) {
    auto it = *Q.begin(); Q.erase(Q.begin());
    int d = it.first.first, u = it.second; double p = it.first.second;

    for(auto it: G[u]) {
      int v = it.first; double p2 = it.second;
      double newp = p + p2 - (p * p2);

      if(D[v] > D[u] + 1 || (D[v] == D[u] + 1 && newp < P[v])) {
        if(D[v] != INT_MAX/2) {
          Q.erase({{D[v], P[v]}, v});
        }
        D[v] = D[u] + 1;
        P[v] = newp;
        par[v] = u;
        Q.insert({{D[v], P[v]}, v});
      }
    }
  }

  cout << D[t] << " " << setprecision(8) << P[t] << endl;
  vector<int> path;

  int x = t;
  while(x != -1) {
    path.push_back(x);
    x = par[x];
  }
  reverse(path.begin(), path.end());

  for(auto it: path) cout << it << " "; cout << endl;
}


