// Exam

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

inline int abs(int a) {
	return (a < 0 ? -a : a);
}

int main() {
	int N; scanf("%d", &N);
	if(N == 1) printf("1\n1\n");
	else if(N == 2) printf("1\n1\n");
	else if(N == 3) printf("2\n1 3\n");
	else if(N == 4) printf("4\n3 1 4 2\n");
	else {
		set<int> remain; for(int i = 1; i <= N; i++) remain.insert(i);
		vector<int> ans;
		while(remain.size() > 1){
			int curr_min = *remain.begin();
			int other = N - curr_min;
			if(abs(curr_min - other) <= 1){
				other = N;
			}
			if(ans.size() > 0 && abs(*ans.rbegin() - curr_min) == 1){
				ans.push_back(other);
				ans.push_back(curr_min);
			}
			else {
				ans.push_back(curr_min);
				ans.push_back(other);
			}
			remain.erase(other);
			remain.erase(curr_min);
		}
		if(remain.size() > 0 && (*ans.rbegin() - *remain.begin()) != 1) {
			ans.push_back(*remain.begin());
		}
		printf("%d\n", ans.size());
		for(auto it: ans) printf("%d ", it);
		printf("\n");
	}
}
