#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>

using namespace std;

int A[1001];
int timer;
vector<int> G[1001];
int dfs_num[1001], dfs_low[1001];
stack<int> S;
bool on_stack[1001];
vector<vector<int> > scc;
int scc_id[1001];
set<int> G2[1001];
int dp[1001][1001];
int vis[1001];
vector<int> topo;

void dfs(int i) {
	dfs_num[i] = dfs_low[i] = ++timer;
	S.push(i);
	on_stack[i] = true;
	
	for(int u: G[i]) {
		if(dfs_num[u] == 0) {
			dfs(u);
			dfs_low[i] = min(dfs_low[i], dfs_low[u]);
		}
		
		if(on_stack[u]) {
			dfs_low[i] = min(dfs_low[i], dfs_num[u]);
		}
	}
	
	if(dfs_num[i] == dfs_low[i]) {
		scc.push_back({});
		while(!S.empty()) {
			int u = S.top(); S.pop();
			on_stack[u] = false;
			scc.back().push_back(u);
			scc_id[u] = scc.size() - 1;
			if(u == i) break;
		}
	}
}

void dfs_topo(int i) {
	if(vis[i]) return;
	vis[i] = true;
	
	for(int u: G2[i]) {
		dfs_topo(u);
	}
	topo.push_back(i);
}

bool compare(int i, int j) {
	return A[i] < A[j];
}

// i = current scc, j = previous LIS value
int solve(int i, int j) {
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	int ind = 0;
	while(ind < scc[i].size() && A[scc[i][ind]] < j) ind++;
	
	int curr = 0;
	while(ind < scc[i].size()) {
		curr++;
		for(int u: G2[i]) {
			ans = max(ans, curr + solve(u, A[scc[i][ind]]));
		}
		ans = max(ans, curr);
		ind++;
	}
	for(int u: G2[i]) {
		ans = max(ans, solve(u, j));
	}
	
	return dp[i][j] = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int N, M; cin >> N >> M;
	
	map<int, int> compres;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		compres[A[i]] = 0;
	}
	
	timer = 0;
	for(auto it: compres) {
		compres[it.first] = ++timer;
	}
	for(int i = 1; i <= N; i++) {
		A[i] = compres[A[i]];
	}
	
	while(M--) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}
	
	timer = 0;
	for(int i = 1; i <= N; i++) {
		if(dfs_num[i]) continue;
		dfs(i);
	}
	
	for(int i = 1; i <= N; i++) {
		for(int u: G[i]) {
			if(scc_id[i] != scc_id[u]) G2[scc_id[i]].insert(scc_id[u]);
		}
	}
	
	for(int i = 0; i < scc.size(); i++) {
		if(!vis[i]) dfs_topo(i);
	}
	reverse(topo.begin(), topo.end());
	
	/*
	for(int i = 0; i < scc.size(); i++) {
		cout << i << ": ";
		for(int u: scc[i]) cout << u << " "; cout << endl;
	}
	cout << "TEMP" << endl;
	for(int i = 0; i < scc.size(); i++) {
		cout << i << ": ";
		for(int u: G2[i]) cout << u << " "; cout << endl;
	}*/
	
	for(int i = 0; i < scc.size(); i++) {
		sort(scc[i].begin(), scc[i].end(), compare);
	}
	
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			dp[i][j] = -1;
		}
	}
	
	int ans = 0;
	for(int i: topo) {
		ans = max(ans, solve(i, 0));
	}
	cout << ans << endl;
}
