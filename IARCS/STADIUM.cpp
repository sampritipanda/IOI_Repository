// The Siruseri Sports Stadium

#include <stdio.h>
#include <utility>
#include <algorithm>

int main(){
  int N; scanf("%d", &N);

  std::pair<int, int> events[N];

  for(int i = 0; i < N; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    events[i] = std::make_pair(a, b);
  }

  std::sort(events, events + N);

  int curr_end = 0, count = 0;
  for(int i = 0; i < N; i++){
    if(events[i].first >= curr_end){
      curr_end = events[i].first + events[i].second;
      count++;
    }
  }

  printf("%d\n", count);
}
