// Minimum Difficulty

#include <stdio.h>
#include <algorithm>

int main() {
  int n; scanf("%d", &n);
  int track[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &track[i]);
  }

  int difficulty = 0;
  for(int i = 0; i < n - 1; i++){
    if((track[i+1] - track[i]) > difficulty) difficulty = track[i+1] - track[i];
  }

  int minDiff = 10000000;
  for(int i = 1; i < n - 1; i++){
    int diff = track[i + 1] - track[i - 1];
    if(diff < minDiff) minDiff = diff;
  }

  printf("%d\n", std::max(minDiff, difficulty));
}
