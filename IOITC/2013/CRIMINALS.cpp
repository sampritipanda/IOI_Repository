#include <iostream>
#include <algorithm>

using namespace std;

bool vis[100001];

int criminalEstimate(int N, int M, int* A, int* B) {
  for(int i = 0; i <= M; i++) vis[i] = true;

  for(int i = 1; i <= M; i++) {
    if(!vis[i]) continue;

    for(int j = 1; j <= M; j++) {
      if(j == i || !vis[j]) continue;

      if(A[j] <= A[i] && B[i] <= B[j]) vis[j] = false;
    }
  }

  int cnt = 0;
  for(int i = 1; i <= M; i++) {
    if(vis[i]) cnt++;
  }
  return cnt;
}
