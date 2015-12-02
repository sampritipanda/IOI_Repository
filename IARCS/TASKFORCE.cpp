#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> cnt;
vector<bool> taken;

int main() {
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	
	G.resize(N + 1);
	taken.resize(N + 1);
	cnt.resize(N + 1, 0);
	
	for(int i = 1; i <= N; i++) taken[i] = true;
	
	while(M--) {
		int A, B; scanf("%d %d", &A, &B);
		cnt[A]++; cnt[B]++;
		G[A].push_back(B); G[B].push_back(A);
	}
	
	while(true) {
		int per = -1, smallest = 1000101;
		for(int i = 1; i <= N; i++) {
			if(taken[i] && cnt[i] < K && cnt[i] < smallest) {
				smallest = cnt[i]; per = i;
			}
		}
			
		if(per == -1) break;
		else {
			taken[per] = false;
			for(int i = 0; i < G[per].size(); i++) {
				cnt[G[per][i]]--;
			}
			cnt[per] = 0;
		}
	}
	
	int size = 0;
	for(int i = 1; i <= N; i++) {
		if(taken[i]) size++;
	}	
	
	if(size == 0) printf("NO\n");
	else printf("YES\n%d\n", size);
	
	return 0;
}