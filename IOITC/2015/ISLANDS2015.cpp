#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>

using namespace std;

vector<pair<int, pair<int, int> > > edges;
int U[1000001];
int sz[1000001];

int find(int i) {
  if(i == U[i]) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    U[a] = b;
    sz[b] += sz[a];
    sz[a] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

int N; cin >> N;

  for(int i = 0; i < N - 1; i++) {
    int x, y, z; cin >> x >> y >> z;
    edges.push_back({z, {x, y}});
  }

  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());

  for(int i = 1; i <= N; i++) {
    U[i] = i;
    sz[i] = 1;
  }

  long long ans = 0;
  for(auto it: edges) {
    int w = it.first, u = it.second.first, v = it.second.second;

    if(find(u) == find(v)) continue;
    else {
      u = find(u);
      v = find(v);
      ans += 1LL * sz[u] * sz[v] * w;
      merge(u, v);
    }
  }
  cout << ans << endl;
}
