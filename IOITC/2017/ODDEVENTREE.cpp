#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
long long dp_down[100001][2];
long long dp_up[100001][2];
long long dp_subtree[100001][2];

void dfs_down(int u, int p) {
	for(int v: G[u]) {
		if(v == p) continue;
		dfs_down(v, u);
	}
	
	dp_down[u][0] = 1;
	dp_down[u][1] = 0;
	for(int v: G[u]) {
		if(v == p) continue;
		dp_down[u][0] += dp_down[v][1];
		dp_down[u][1] += dp_down[v][0];
	}
	
	long long sum_0 = 0, sum_1 = 0;
	dp_subtree[u][0] = 0; dp_subtree[u][1] = 0;
	for(int v: G[u]) {
		if(v == p) continue;
		
		dp_subtree[u][0] += sum_0 * dp_down[v][1];
		dp_subtree[u][0] += sum_1 * dp_down[v][0];
		
		dp_subtree[u][1] += sum_0 * dp_down[v][0];
		dp_subtree[u][1] += sum_1 * dp_down[v][1];
		
		sum_0 += dp_down[v][1];
		sum_1 += dp_down[v][0];
	}
}

void dfs_up(int u, int p, long long sum_0 = 0, long long sum_1 = 0) {
	dp_up[u][0] = sum_0;
	dp_up[u][1] = sum_1;
	
	sum_0 += dp_down[u][0];
	sum_1 += dp_down[u][1];
	
	for(int v: G[u]) {
		if(v == p) continue;
		
		sum_0 -= dp_down[v][1];
		sum_1 -= dp_down[v][0];
		
		dfs_up(v, u, sum_1, sum_0);
		
		sum_0 += dp_down[v][1];
		sum_1 += dp_down[v][0];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int N; cin >> N;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs_down(1, 0);
	dfs_up(1, 0);
	
	for(int i = 1; i <= N; i++) {
		long long even = 0;
		even += (dp_up[i][0] + 1) * dp_down[i][0];
		even += dp_up[i][1] * dp_down[i][1];
		even += dp_subtree[i][0];
		
		long long odd = 0;
		odd += (dp_up[i][0] + 1) * dp_down[i][1];
		odd += dp_up[i][1] * dp_down[i][0];
		odd += dp_subtree[i][1];
		
		cout << odd << " " << even << endl;
	}
}
