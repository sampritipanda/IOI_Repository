// Anya and Smartphone

#include <stdio.h>
#include <iostream>
#include <cmath>

int apps[100001], previous[100001], next[100001];

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);

  int prev = 0;
  for(int i = 0; i < N; i++) {
    int curr; scanf("%d", &curr);
    apps[curr] = i + 1;
    previous[curr] = prev;
    next[prev] = curr;
    prev = curr;
  }
  next[prev] = 0;

  long long count = 0;
  for(int i = 0; i < M; i++){
    int curr; scanf("%d", &curr);
    count += (apps[curr] - 1)/K + 1;
    if(apps[curr] > 1) {
      int first = previous[curr], second = curr;
      int p = previous[first], n = next[second];
      apps[first]++; apps[second]--;
      previous[first] = second;
      previous[second] = p;
      next[first] = n;
      next[second] = first;
      next[p] = second;
      previous[n] = first;
    }
  }

  std::cout << count << std::endl;
}
