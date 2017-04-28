#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

const long long MOD = 1000000007LL;
const long long INV_2 = 500000004LL;
vector<int> comps[100001][2];
int color[100001];
int comp_color[100001][2][2];
int comp_id[100001];
int comp_side[100001];
set<int> invalid_comps;

void merge(int u, int v) {
  if(comps[comp_id[u]][0].size() + comps[comp_id[u]][1].size() < comps[comp_id[v]][0].size() + comps[comp_id[v]][1].size()) swap(u, v);

  int comp_id_v = comp_id[v];
  int comp_side_v = comp_side[v];

  for(int x: comps[comp_id_v][comp_side_v]) {
    comps[comp_id[u]][comp_side[u] ^ 1].push_back(x);
    comp_id[x] = comp_id[u];
    comp_side[x] = comp_side[u] ^ 1;
  }
  comp_color[comp_id[u]][comp_side[u] ^ 1][0] += comp_color[comp_id_v][comp_side_v][0];
  comp_color[comp_id[u]][comp_side[u] ^ 1][1] += comp_color[comp_id_v][comp_side_v][1];

  for(int x: comps[comp_id_v][comp_side_v ^ 1]) {
    comps[comp_id[u]][comp_side[u]].push_back(x);
    comp_id[x] = comp_id[u];
    comp_side[x] = comp_side[u];
  }
  comp_color[comp_id[u]][comp_side[u]][0] += comp_color[comp_id_v][comp_side_v ^ 1][0];
  comp_color[comp_id[u]][comp_side[u]][1] += comp_color[comp_id_v][comp_side_v ^ 1][1];

  invalid_comps.erase(comp_id_v);
  comp_color[comp_id_v][0][0] = 0;
  comp_color[comp_id_v][0][1] = 0;
  comp_color[comp_id_v][1][0] = 0;
  comp_color[comp_id_v][1][1] = 0;

  comps[comp_id_v][0].clear();
  comps[comp_id_v][1].clear();

  if((comp_color[comp_id[u]][0][0] > 0 && comp_color[comp_id[u]][1][0] > 0)
      || (comp_color[comp_id[u]][0][1] > 0 && comp_color[comp_id[u]][1][1] > 0)) {
    invalid_comps.insert(comp_id[u]);
  }
  else {
    invalid_comps.erase(comp_id[u]);
  }
}

inline int num_colored(int id) {
  return comp_color[id][0][0] + comp_color[id][0][1] + comp_color[id][1][0] + comp_color[id][1][1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Q, k1, k2; cin >> N >> M >> Q >> k1 >> k2;

  long long ans = 1;

  for(int i = 1; i <= N; i++) {
    comps[i][0].push_back(i);
    comp_id[i] = i;
    comp_side[i] = 0;
    color[i] = -1;
    ans = (ans * 2) % MOD;
  }

  while(k1--) {
    int x; cin >> x;
    comp_color[comp_id[x]][comp_side[x]][0]++;
    color[x] = 0;
    ans = (ans * INV_2) % MOD;
  }
  while(k2--) {
    int x; cin >> x;
    comp_color[comp_id[x]][comp_side[x]][1]++;
    color[x] = 1;
    ans = (ans * INV_2) % MOD;
  }

  while(M--) {
    int u, v; cin >> u >> v;
    if(comp_id[u] == comp_id[v]) continue;
    if(num_colored(comp_id[u]) == 0 || num_colored(comp_id[v]) == 0) ans = (ans * INV_2) % MOD;
    merge(u, v);
  }

  while(Q--) {
    int t; cin >> t;

    if(t == 0) {
      int u; char c; cin >> u >> c;
      int col = (c == 'U' ? -1 : (c == 'A' ? 0 : 1));
      int prev_num_colored = num_colored(comp_id[u]);
      if(color[u] != -1) comp_color[comp_id[u]][comp_side[u]][color[u]]--;
      color[u] = col;
      if(color[u] != -1) comp_color[comp_id[u]][comp_side[u]][color[u]]++;

      if(prev_num_colored == 0 && num_colored(comp_id[u]) > 0) ans = (ans * INV_2) % MOD;
      else if(prev_num_colored > 0 && num_colored(comp_id[u]) == 0) ans = (ans * 2) % MOD;

      if((comp_color[comp_id[u]][0][0] > 0 && comp_color[comp_id[u]][1][0] > 0)
          || (comp_color[comp_id[u]][0][1] > 0 && comp_color[comp_id[u]][1][1] > 0)) {
        invalid_comps.insert(comp_id[u]);
      }
      else {
        invalid_comps.erase(comp_id[u]);
      }
    }
    else if(t == 1) {
      int u, v; cin >> u >> v;
      if(comp_id[u] == comp_id[v]) continue;
      if(num_colored(comp_id[u]) == 0 || num_colored(comp_id[v]) == 0) ans = (ans * INV_2) % MOD;
      merge(u, v);
    }
    else {
      if(invalid_comps.size() > 0) cout << 0 << endl;
      else cout << ans << endl;
    }
  }
}
