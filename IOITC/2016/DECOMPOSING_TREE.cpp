#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int P[100001];
set<int> G[100001];

int calc(int i) {
	int ans = 0;
	if(i == 1) {
		ans += ceil(int(G[i].size())/2.0);
	}
	else {
		ans += int(G[i].size())/2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int N; cin >> N;
	for(int i = 2; i <= N; i++) {
		cin >> P[i];
		G[P[i]].insert(i);
	}
	
	int Q; cin >> Q;
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += calc(i);	
	}
	
	cout << ans << endl;
	
	while(Q--) {
		int v, u; cin >> v >> u;
		int p = P[v];
		
		ans -= calc(p);
		G[p].erase(v);
		ans += calc(p);
		
		ans -= calc(u);
		G[u].insert(v);
		ans += calc(u);
		
		P[v] = u;
		
		cout << ans << endl;
	}
}
