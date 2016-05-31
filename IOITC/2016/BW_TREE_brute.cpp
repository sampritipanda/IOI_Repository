#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int C[200001];
int P[200001];
int D[200001];
set<int> G[200001];

void dfs(int i, int d) {
	D[i] = d;
	
	for(int u: G[i]) {
		dfs(u, d + 1);
	}
}

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	
	P[1] = -1;
	for(int i = 2; i <= N; i++) {
		scanf("%d", &P[i]);
		G[P[i]].insert(i);
	}
	
	dfs(1, 0);
	
	while(Q--) {
		char type; scanf(" %c", &type);
		
		if(type == 'T') {
			int u; scanf("%d", &u);
			
			C[u] ^= 1;
		}
		else if(type == 'C') {
			int u, v; scanf("%d %d", &u, &v);
			
			G[P[u]].erase(u);
			P[u] = v;
			G[P[u]].insert(u);
			
			dfs(1, 0);
		}
		else {
			int u, v, k; scanf("%d %d %d", &u, &v, &k);
			
			int a = u, b = v;
			if(D[a] > D[b]) swap(a, b);
		
			while(D[a] != D[b]) {
				b = P[b];
			}
			
			while(a != b) {
				a = P[a]; b = P[b];
			}
			
			int l = a;
			
			vector<int> path, path2;
			while(true) {
				path.push_back(u);
				if(u == l) break;
				u = P[u];
			}
			while(v != l) {
				path2.push_back(v);
				v = P[v];
			}
			reverse(path2.begin(), path2.end());
			for(auto it: path2) path.push_back(it);
			
			int ans = -1, cnt = 0;
			for(int u: path) {
				cnt += C[u];
				if(cnt == k) {
					ans = u;
					break;
				}
			}
			
			printf("%d\n", ans);
		}
	}
}
