#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[200001];
int deg[200001];
int vis[200001];
int covered[200001];
int dist[2001][2001];
queue<int> leaves;
vector<int> curr_reached_leaves;

void check_validity(int u, int p, int d) {
	if(deg[u] <= 1 && !covered[u]) curr_reached_leaves.push_back(u);
	for(int v: G[u]) {
		if(v == p) continue;
		if(d > 0) check_validity(v, u, d - 1);
	}
}

void dfs(int u, int p, int d) {
	covered[u] = true;
	for(int v: G[u]) {
		if(v == p) continue;
		if(d > 0) {
			dfs(v, u, d - 1);
		}
		else {
			deg[v]--;
			if(deg[v] <= 1) leaves.push(v);
		}
	}
}

void dfs_dist(int s, int u, int p, int d) {
	dist[s][u] = d;
	
	for(int v: G[u]) {
		if(v == p) continue;
		dfs_dist(s, v, u, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int N, D; cin >> N >> D;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++; deg[v]++;
	}
	
	for(int i = 1; i <= N; i++) dfs_dist(i, i, 0, 0);
	
	for(int i = 1; i <= N; i++) {
		if(deg[i] <= 1) leaves.push(i);
	}
	
	int ans = 0;
	
	while(!leaves.empty()) {
		int u = leaves.front(); leaves.pop();
		if(vis[u]) continue;
		if(covered[u]) continue;
		if(u == 53 || u == 8) {
			int debug = 1;
		}
		
		check_validity(u, 0, D - 1);
		bool is_there_better = false;
		for(int i = 0; i < curr_reached_leaves.size(); i++) {
			if(curr_reached_leaves[i] == u) continue;
			for(int j = i + 1; j < curr_reached_leaves.size(); j++) {
				if(curr_reached_leaves[j] == u) continue;
				if(dist[curr_reached_leaves[i]][curr_reached_leaves[j]] >= D) {
					is_there_better = true;
					break;
				}
			}
			if(is_there_better) break;
		}
		curr_reached_leaves.clear();
		
		if(is_there_better) {
			leaves.push(u);
			continue;
		}
		
		ans++;
		vis[u] = true;
		dfs(u, 0, D - 1);		
	}
	
	cout << ans << endl;
	for(int i = 1; i <= N; i++) if(vis[i]) cout << i << " "; cout << endl;
}
