#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define MAX_LOG 18

int N;
int C[200001];
int P[200001];
vector<int> G[200001];
set<int> G2[200001];
int D[200001];
int sz[200001];
int heavy_child[200001];
int lca[200001][MAX_LOG];
bool vis[200001];
bool leaf[200001];

vector<int> paths[200001];
vector<int> bit[200001];
int chain_id[200001];
int path_index[200001];

void dfs(int i, int d) {
	sz[i] = 1;
	D[i] = d;
	heavy_child[i] = -1;
	leaf[i] = true;
	
	for(int u: G[i]) {
		leaf[i] = false;
		dfs(u, d + 1);
		sz[i] += sz[u];
	}
	
	int max_size = 0;
	for(int u: G[i]) {
		if(sz[u] > max_size) {
			max_size = sz[u];
			heavy_child[i] = u;
		}
	}	
}

int kth_ancestor(int u, int k) {
	for(int j = MAX_LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) u = lca[u][j];
	}
	return u;
}

int lca_query(int u, int v) {
	if(D[u] > D[v]) swap(u, v);
	
	for(int j = MAX_LOG - 1; j >= 0; j--) {
		if(D[v] - (1 << j) >= D[u]) {
			v = lca[v][j];
		}
	}
	
	if(u == v) return u;
	
	for(int j = MAX_LOG - 1; j >= 0; j--) {
		if(lca[u][j] != -1 && lca[v][j] != -1 && lca[u][j] != lca[v][j]) {
			u = lca[u][j];
			v = lca[v][j];
		}
	}
	
	assert(lca[u][0] == lca[v][0]);
	return lca[u][0];
}

void update(int i, int j, int v) {
	j += 1;
	int M = paths[i].size();
	while(j <= M) {
		bit[i][j] += v;
		j += j & -j;
	}
}

int query(int i, int j) {
	j += 1;
	int ans = 0;
	int M = paths[i].size();
	
	while(j > 0) {
		ans += bit[i][j];
		j -= j & -j;
	}
	
	return ans;
}

inline int range_query(int i, int L, int R) {
	return query(i, R) - query(i, L - 1);
}

// query on path from u -> v ( v is ancestor of u );
int hld_query(int u, int v) {
	int ans = 0;
	while(chain_id[u] != chain_id[v]) {
		ans += range_query(chain_id[u], 0, path_index[u]);
		u = P[paths[chain_id[u]][0]];
	}
	ans += range_query(chain_id[u], path_index[v], path_index[u]);
	return ans;
}

void dfs_brute(int i, int d) {
	D[i] = d;
	
	for(int u: G2[i]) {
		dfs_brute(u, d + 1);
	}
}

int main() {
	int Q; scanf("%d %d", &N, &Q);
	
	if(N <= 1000 && Q <= 1000) {
	
	
	
	
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	
	P[1] = -1;
	for(int i = 2; i <= N; i++) {
		scanf("%d", &P[i]);
		G2[P[i]].insert(i);
	}
	
	dfs_brute(1, 0);
	
	while(Q--) {
		char type; scanf(" %c", &type);
		
		if(type == 'T') {
			int u; scanf("%d", &u);
			
			C[u] ^= 1;
		}
		else if(type == 'C') {
			int u, v; scanf("%d %d", &u, &v);
			
			G2[P[u]].erase(u);
			P[u] = v;
			G2[P[u]].insert(u);
			
			dfs_brute(1, 0);
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
	else {
		
		
		
		
	
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	
	P[1] = -1;
	for(int i = 2; i <= N; i++) {
		scanf("%d", &P[i]);
		G[P[i]].push_back(i);
	}
	
	dfs(1, 1);
	
	for(int j = 0; j < MAX_LOG; j++) {
		for(int i = 1; i <= N; i++) {
			lca[i][j] = -1;
		}
	}
	
	for(int i = 1; i <= N; i++) lca[i][0] = P[i];
	
	for(int j = 1; j < MAX_LOG; j++) {
		for(int i = 1; i <= N; i++) {
			if(lca[i][j - 1] != -1)
				lca[i][j] = lca[lca[i][j - 1]][j - 1];
		}
	}
	
	int id = 0;
	for(int i = 1; i <= N; i++) {
		if(vis[i]) continue;
		if(!leaf[i]) continue;
		
		int u = i;
		while(true) {
			vis[u] = true;
			paths[id].push_back(u);
			if(P[u] == -1) break;
			if(heavy_child[P[u]] != u) break;
			u = P[u];
		}
		reverse(paths[id].begin(), paths[id].end());
		for(int j = 0; j < paths[id].size(); j++) {
			chain_id[paths[id][j]] = id;
			path_index[paths[id][j]] = j;
		}
		bit[id].resize(paths[id].size() + 1);
		
		for(int j = 0; j < paths[id].size(); j++) {
			update(id, j, C[paths[id][j]]);
		}
		
		id++;
	}
	
	while(Q--) {
		char type; scanf(" %c", &type);
		
		if(type == 'T') {
			int u; scanf("%d", &u);
			
			C[u] ^= 1;
			int val = range_query(chain_id[u], path_index[u], path_index[u]);
			if(val == 1) update(chain_id[u], path_index[u], -1);
			else update(chain_id[u], path_index[u], 1);
		}
		else if(type == 'C') {
			int u, v; scanf("%d %d", &u, &v);
			
			assert(false);
		}
		else {
			int u, v, k; scanf("%d %d %d", &u, &v, &k);
			int l = lca_query(u, v);
			
			int left_dist = D[u] - D[l] + 1;
			int right_dist = D[v] - D[l] + 1;
			int dist = left_dist + right_dist - 1;
			
			int L = 1, R = dist;
			while(L <= R) {
				int mid = (L + R)/2;
				int node = -1;
				
				if(mid <= left_dist) {
					node = kth_ancestor(u, mid - 1);
				}
				else {
					int k = right_dist - (mid - left_dist);
					node = kth_ancestor(v, k - 1);
				}
											
				int l2;
				if(mid <= left_dist) l2 = node;
				else l2 = l;
				
				int cnt = hld_query(u, l2) + hld_query(node, l2) - C[l2];
				
				if(cnt >= k) {
					if(L == R) break;
					R = mid;
				}
				else {
					L = mid + 1;
				}
			}
			
			if(L > R) printf("-1\n");
			else {
				if(L <= left_dist) {
					printf("%d\n", kth_ancestor(u, L - 1));
				}
				else {
					int k = right_dist - (L - left_dist);
					printf("%d\n", kth_ancestor(v, k - 1));
				}
			}
		}
	}
	
	
	
	
	}
}
