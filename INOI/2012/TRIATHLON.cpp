// Triathlon

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int N; scanf("%d", &N);
	vector<pair<int, int> > citizens;
	
	for(int i = 0; i < N; i++){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		citizens.push_back(make_pair(b + c, a));
	}
	
	sort(citizens.begin(), citizens.end());
	
	int maxTime = 0;
	int sumFirst = 0;
	
	for(int i = N - 1; i >= 0; i--){
		int time = sumFirst + citizens[i].second + citizens[i].first;
		if(time > maxTime) maxTime = time;
		sumFirst += citizens[i].second;
	}
	
	printf("%d\n", maxTime);
}