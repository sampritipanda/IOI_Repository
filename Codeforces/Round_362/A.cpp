#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<vector<long long>> upd;
map<long long, long long> V;

inline long long log2(long long u) {
  if(u <= 1) return 0;
  return 63 -__builtin_clzll(u);
}

inline long long lca(long long u, long long v) {
  long long d1 = log2(u), d2 = log2(v);
  if(d1 > d2) {
    swap(u, v);
    swap(d1, d2);
  }
  while(d2 > d1) {
    v /= 2;
    d2--;
  }
  while(u != v) {
    u /= 2;
    v /= 2;
  }
  return u;
}

void update(long long u, long long v, long long w) {
  while(v != u) {
    V[v] += w;
    v /= 2;
  }
}

long long calc(long long u, long long v) {
  long long ans = 0;
  while(v != u) {
    ans += V[v];
    v /= 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int Q; cin >> Q;

  while(Q--) {
    int t; cin >> t;

    if(t == 1) {
      long long u, v, w; cin >> u >> v >> w;
      long long l = lca(u, v);

      update(l, u, w);
      update(l, v, w);
    }
    else {
      long long u, v; cin >> u >> v;
      long long l = lca(u, v);

      long long ans = calc(l, u) + calc(l, v);
      cout << ans << endl;
    }
  }
}
