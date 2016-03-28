#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int G[100001];
bool vis[100001], rec[100001], cycle[100001];
int indeg[100001];
int cycle_start = 0;
bool cycle_found = false;
int curr_max = 0;

void dfs(int i) {
  if(rec[i]) {
    cycle_start = i;
    return;
  }
  if(vis[i]) return;

  vis[i] = true;
  rec[i] = true;
  if(G[i] != i) dfs(G[i]);
  rec[i] = false;
}

void mark_cycle(int i) {
  if(i == cycle_start) return;
  cycle[i] = true;
  mark_cycle(G[i]);
}

void dfs2(int i) {
  if(vis[i]) return;
  vis[i] = true;

  if(cycle[i]) {
    cycle_found = true;
  }

  if(!cycle[i]) curr_max++;
  dfs2(G[i]);
}

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> G[i];
    if(G[i] != i) indeg[G[i]]++;
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    cycle_start = 0;
    dfs(i);
    if(cycle_start) {
      cycle[cycle_start] = true;
      mark_cycle(G[cycle_start]);
    }
  }

  int ans_min = 0, ans_max = 0;

  for(int i = 0; i <= N; i++) vis[i] = false;

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    if(indeg[i] > 0) continue; // not a leaf

    cycle_found = false;
    curr_max = 0;
    dfs2(i);
    ans_min += 1;
    ans_max += curr_max;
    if(cycle_found) {
      ans_max++;
    }
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    curr_max = 0;
    dfs2(i);
    ans_min += 1;
    ans_max += curr_max;
    if(cycle_found) ans_max++;
  }

  cout << ans_min << " " << ans_max << endl;
}
