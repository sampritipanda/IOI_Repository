#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int A[100001];
vector<pair<int, int> > queries;
int W[100001];
int bit[100001];
map<pair<int, int>, long long> query_map;

const int BLOCK_SIZE = 500;

bool compare(pair<int, int> A, pair<int, int> B) {
	if(A.first/BLOCK_SIZE == B.first/BLOCK_SIZE) return A.second < B.second;
	return A.first/BLOCK_SIZE < B.first/BLOCK_SIZE;
}

int query(int i) {
	int ans = 0;
	while(i > 0) {
		ans += bit[i];
		i -= i & -i;
	}
	return ans;
}

void update(int i, int v) {
	if(i == 0) return;
	while(i <= 100000) {
		bit[i] += v;
		i += i & -i;
	}
}

int main() {
	int N, Q; scanf("%d %d", &N, &Q);
	
	map<int, int> compres;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		compres[A[i]] = 0;
	}
	
	int timer = 0;
	for(auto it: compres) {
		compres[it.first] = ++timer;
	}
	for(int i = 1; i <= N; i++) {
		A[i] = compres[A[i]];
	}
	
	set<int> walls;
	walls.insert(0); walls.insert(N);
	queries.push_back({1, N});
	for(int i = 1; i <= Q; i++) {
		scanf("%d", &W[i]);
		walls.insert(W[i]);
		auto it = walls.find(W[i]);
		it--;
		queries.push_back({*it + 1, W[i]});
		it++;
		it++;
		queries.push_back({W[i] + 1, *it});
	}
	
	sort(queries.begin(), queries.end(), compare);
	int L = 1, R = 0;
	long long ans = 0;
	
	for(auto it: queries) {
		int curr_L = it.first, curr_R = it.second;
		while(R < curr_R) {
			++R;
			ans += query(100000) - query(A[R]);
			update(A[R], 1);
		}
		while(R > curr_R) {
			ans -= query(100000) - query(A[R]);
			update(A[R], -1);
			R--;
		}
		while(L < curr_L) {
			ans -= query(A[L] - 1);
			update(A[L], -1);
			L++;
		}
		while(L > curr_L) {
			L--;
			ans += query(A[L] - 1);
			update(A[L], 1);
		}
		
		query_map[{curr_L, curr_R}] = ans;
	}
	
	walls.clear();
	walls.insert(0); walls.insert(N);
	ans = query_map[{1, N}];
	
	for(int i = 1; i <= Q; i++) {
		walls.insert(W[i]);
		auto it = walls.find(W[i]);
		it--;
		int prev_L = *it;
		it++;
		it++;
		int prev_R = *it;
		
		ans -= query_map[{prev_L + 1, prev_R}];
		ans += query_map[{prev_L + 1, W[i]}];
		ans += query_map[{W[i] + 1, prev_R}];
		
		printf("%lld\n", ans);
	}
}
