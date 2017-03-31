#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

long long pow2[200001];
int G[200001];
vector<int> G_undir[200001];
int col[200001];
int comp_size[200001];
bool on_stack[200001];
int cycle_size[200001];

void dfs(int i, int c) {
  if(col[i]) return;
  col[i] = c;

  for(int v: G_undir[i]) {
    dfs(v, c);
  }
}

int dfs_cycle(int i) {
  if(on_stack[i]) return i;
  on_stack[i] = true;

  int x = dfs_cycle(G[i]);
  if(x != 0) cycle_size[col[i]]++;

  if(x == i) return 0;
  return x;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  pow2[0] = 1;
  for(int i = 1; i <= N; i++) pow2[i] = (pow2[i - 1] * 2) % MOD;

  for(int i = 1; i <= N; i++) {
    cin >> G[i];
    G_undir[i].push_back(G[i]);
    G_undir[G[i]].push_back(i);
  }

  for(int i = 1; i <= N; i++) {
    if(col[i]) continue;
    dfs(i, i);
  }

  for(int i = 1; i <= N; i++){
    comp_size[col[i]]++;
    if(cycle_size[col[i]]) continue;
    dfs_cycle(i);
  }

  long long ans = 1;

  for(int i = 1; i <= N; i++) {
    if(comp_size[i] == 0) continue;

    long long curr = (pow2[cycle_size[i]] - 2 + MOD) % MOD;
    curr = (curr * pow2[comp_size[i] - cycle_size[i]]) % MOD;
    ans = (ans * curr) % MOD;
  }

  cout << ans << endl;
}
