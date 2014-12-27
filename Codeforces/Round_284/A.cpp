// Watching a movie

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int N, x; scanf("%d %d", &N, &x);
  vector<pair<int, int> > moments;

  for(int i = 0; i < N; i++){
	int l, r;
    scanf("%d %d", &l, &r);
	moments.push_back(make_pair(l, r));
  }
  
  sort(moments.begin(), moments.end());
  int end = moments[N - 1].second;
  
  int current_minute = 1;
  int total_time = 0;
  int i = 0;
  while(i < N && current_minute <= end){
	if(moments[i].first - current_minute >= x){
		current_minute += ((moments[i].first - current_minute)/x) * x;
	}
	else {
		total_time += moments[i].second - current_minute + 1;
		current_minute = moments[i].second + 1;
		i++;
	}
  }
  
  printf("%d\n", total_time);
}
