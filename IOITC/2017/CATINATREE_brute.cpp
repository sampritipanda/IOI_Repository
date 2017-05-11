#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[20];
int vis[20];
bool valid;

void mark_and_check(int u, int p, int d) {
	if(d == 0) return;
	
	for(int v: G[u]) {
		if(v == p) continue;
		if(vis[v]) valid = false;
		mark_and_check(v, u, d - 1);
	}
}

int main() {
	int N, D; cin >> N >> D;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int ans = 0;
	for(int mask = 0; mask < (1 << N); mask++) {
		for(int i = 0; i < N; i++) vis[i] = 0;
		valid = true;
		for(int i = 0; i < N; i++) {
			if(mask & (1 << i)) {
				vis[i] = 1;
				mark_and_check(i, -1, D - 1);
				if(!valid) break;
			}
		}
		if(valid) {
			int curr = __builtin_popcount(mask);
			if(curr > ans) {
				ans = curr;
				//cout << ans << " => ";
				//for(int i = 0; i < N; i++) {
				//	if(vis[i]) cout << i + 1 << " ";
				//}
				//cout << endl;
			}
		}
	}
	
	cout << ans << endl;
}
