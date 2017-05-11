#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

int N;
long long C[100001], H[100001];
vector<int> G[100001];
long long dp[100002];
int depth[100002];
int h;

/*

sum(C[j] * (N - i) + C[j] * C[j]) - H[u]
C[j] * sum (N - i) + sum(C[j] * C[j])) - H[j]

*/

int dfs(int i, int p, int d) {
	depth[i] = d;
	
	for(int u: G[i]) {
		if(u != p) {
			dfs(u, i, d + 1);
		}
	}
}

long long traverse(int i, int p, int start_d, long long sum) {
	sum += h - depth[i];
	long long ans = LLONG_MAX/2;
	long long sub_sum = 0;
	for(int u: G[i]) {
		if(u == p) continue;
		sub_sum += dp[u];
	}
	
	ans = min(ans, (C[i] * sum) + (C[i] * C[i] * (depth[i] - start_d + 1)) - H[i] + sub_sum);
	
	for(int u: G[i]) {
		if(u == p) continue;
		sub_sum -= dp[u];
		ans = min(ans, traverse(u, i, start_d, sum) + sub_sum);
		sub_sum += dp[u];
	}
	
	return ans;
}

long long solve(int i, int p) {
	for(int u: G[i]) {
		if(u == p) continue;		
		solve(u, i);
	}
	
	dp[i] = traverse(i, p, depth[i], 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> N;
	assert(N <= 5000);
	for(int i = 1; i <= N; i++) cin >> H[i] >> C[i];
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0, 0);
	for(int i = 1; i <= N; i++) h = max(h, depth[i]);
	solve(1, 0);
	
	cout << dp[1] << endl;
}
