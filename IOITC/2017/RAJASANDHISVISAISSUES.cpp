#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define MOD 1000000007LL

int F[100001];
vector<int> G[100001];
int vis[100001];
int max_val;
map<int, int> freq;
vector<int> primes;

void dfs(int i) {
	if(vis[i]) return;
	vis[i] = 1;
	max_val = max(max_val, F[i]);
	
	for(int u: G[i]) {
		dfs(u);
	}
}

int main() {
	for(int i = 2; i <= 1000; i++) {
		bool is_prime = true;
		for(int j = 2; j * j <= i; j++) {
			if(i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if(is_prime) primes.push_back(i);
	}
	int T; scanf("%d", &T);
	
	while(T--) {
		int N, M; scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &F[i]);
		for(int i = 1; i <= N; i++) {
			G[i].clear();
			vis[i] = 0;
		}
		freq.clear();
		
		while(M--) {
			int u, v; scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		set<int> vals;
		for(int i = 1; i <= N; i++) {
			if(vis[i]) continue;
			max_val = 0;
			dfs(i);
			vals.insert(max_val);
		}
		
		for(int x: vals) {
			for(int p: primes) {
				int curr_freq = 0;
				while(x % p == 0) {
					curr_freq++;
					x /= p;
				}
				if(curr_freq > 0) freq[p] = max(freq[p], curr_freq);
			}
			if(x > 1) freq[x] = max(freq[x], 1);
		}
		
		long long ans = 1;
		for(auto it: freq) {
			for(int j = 0; j < it.second; j++) {
				ans = (ans * it.first) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
}
