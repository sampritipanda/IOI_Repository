#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int dp[(1 << 20) + 100][2][25];
int H, N;
int V[(1 << 20) + 100];
int C[(1 << 20) + 100];
int b;

inline int anc_value(int i, int k) {
	return V[i/(1 << k)];
}

// solve(i, j, k) => ith subtree, j = changed/not changed, k => element just less than kth ancestor
int solve_0(int i, int j, int k) {
	assert(j == 0 || j == 1);
	
	if(2 * i > N) {
		if(j == 0) return 0;
		else return C[i];
	}
	if(dp[i][j][k] != -1) return dp[i][j][k];
	
	if(j == 1) {
		int val = anc_value(i, k);
		dp[i][j][k] = C[i];
		int left = solve_0(2*i, 1, k + 1);
		if(val >= V[2*i]) left = min(left, solve_0(2*i, 0, 0));
		int right = solve_0(2*i + 1, 1, k + 1);
		if(val >= V[2*i + 1]) right = min(right, solve_0(2*i + 1, 0, 0));
		dp[i][j][k] += left + right;
	}
	else {
		dp[i][j][k] = 0;
		int left = solve_0(2*i, 1, 1);
		if(V[2*i] <= V[i]) left = min(left, solve_0(2*i, 0, 0));
		int right = solve_0(2*i + 1, 1, 1);
		if(V[2*i + 1] <= V[i]) right = min(right, solve_0(2*i + 1, 0, 0));
		
		dp[i][j][k] = left + right;
	}
	
	return dp[i][j][k];
}

int solve_1(int i, int j, int k) {
	assert(j == 0 || j == 1);
	
	if(2 * i > N) {
		if(j == 0) return 0;
		else return C[i];
	}
	if(dp[i][j][k] != -1) return dp[i][j][k];
	
	if(j == 1) {
		assert(k >= 1);
		int val = anc_value(i, k);
		dp[i][j][k] = C[i];
		int left = solve_1(2*i, 1, k + 1);
		if(val - k > V[2*i]) left = min(left, solve_1(2*i, 0, 0));
		int right = solve_1(2*i + 1, 1, k + 1);
		if(val - k > V[2*i + 1]) right = min(right, solve_1(2*i + 1, 0, 0));
		dp[i][j][k] += left + right;
	}
	else {
		dp[i][j][k] = 0;
		int left = solve_1(2*i, 1, 1);
		if(V[2*i] < V[i]) left = min(left, solve_1(2*i, 0, 0));
		int right = solve_1(2*i + 1, 1, 1);
		if(V[2*i + 1] < V[i]) right = min(right, solve_1(2*i + 1, 0, 0));
		
		dp[i][j][k] = left + right;
	}
	
	return dp[i][j][k];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> H;
	N = (1 << H) - 1;
	
	V[0] = 2000000000;
	
	for(int i = 1; i <= N; i++) cin >> V[i];
	for(int i = 1; i <= N; i++) cin >> C[i];
	
	cin >> b;
	
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k <= H; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	
	if(b == 0) {
		cout << min(solve_0(1, 0, 0), solve_0(1, 1, 1)) << endl;
	}
	else {
		cout << min(solve_1(1, 0, 0), solve_1(1, 1, 1)) << endl;
	}
}
