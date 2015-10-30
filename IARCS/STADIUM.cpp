// The Siruseri Sports Stadium

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > events, sort_arr;

int main(){
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    events.push_back({a, b});
    sort_arr.push_back({a + b, i});
  }

  sort(sort_arr.begin(), sort_arr.end());

  int curr_end = 0, count = 0;

  for(int i = 0; i < N; i++){
    int j = sort_arr[i].second;
    if(events[j].first > curr_end){
      curr_end = events[j].first + events[j].second;
      count++;
    }
  }

  printf("%d\n", count);
}
