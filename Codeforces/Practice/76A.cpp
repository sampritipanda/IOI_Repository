#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<long long> > edges;  // {Cost, Gold, Silver, X, Y}
vector<int> U;

int find(int i) {
  if(U[i] == i) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    U[a] = b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;
  long long G, S; cin >> G >> S;

  U.resize(N + 1);
  for(int i = 0; i <= N; i++) U[i] = i;

  while(M--) {
    int x, y; long long g, s; cin >> x >> y >> g >> s;
    long long cost = g * G + s * S;

    edges.push_back({cost, g, s, x, y});
    edges.push_back({cost, g, s, y, x});

    merge(x, y);
  }

  bool possible = true;
  for(int i = 2; i <= N; i++) {
    if(find(1) != find(i)) {
      possible = false;
      break;
    }
  }

  if(possible) {
    for(int i = 0; i <= N; i++) U[i] = i;
    sort(edges.begin(), edges.end());

    long long g_max = 0, s_max = 0;
    for(auto it: edges) {
      int x = it[3], y = it[4]; long long g = it[1], s = it[2];

      if(find(x) != find(y)) {
        g_max = max(g_max, g);
        s_max = max(s_max, s);
        merge(x, y);
      }
    }
    cout << g_max * G + s_max * S << endl;
  }
  else {
    cout << -1 << endl;
  }
}

