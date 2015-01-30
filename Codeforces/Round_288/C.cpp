// Anya and Ghosts

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int m, t, r; scanf("%d %d %d", &m, &t, &r);
  int W[m];
  for(int i = 0; i < m; i++) scanf("%d", &W[i]);

  sort(W, W + m);
  int end_time = W[m - 1];
  int start_time = W[0] - r;

  int next_ghost = 0;
  int total_candles = 0;
  queue<int> candles;
  bool possible = true;
  int last_end_time = -1;
  for(int i = start_time; i <= end_time + 1; i++){
    if(!candles.empty() && i == candles.front() + 1){
      candles.pop();
    }
    if(i == W[next_ghost]){
      if(candles.size() < r) {
        possible = false;
        break;
      }
      else {
        next_ghost = upper_bound(W, W + m, last_end_time) - W;
        if(next_ghost == m) break;
      }
    }
    if(i >= W[next_ghost] - r && i < W[next_ghost]){
      candles.push(i + t);
      total_candles++;
      last_end_time = i + t;
      printf("%d\n", i + t);
    }
  }

  if(possible) printf("%d\n", total_candles);
  else printf("-1\n");
}
