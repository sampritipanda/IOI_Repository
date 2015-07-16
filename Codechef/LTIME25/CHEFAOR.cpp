// Chef and Bitwise OR Operation
// me

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int N, K;
int A[5001];
int cost[5001][5001];
long long dp[5001][5001];

void divide_and_conquer(int j, int L, int R, int search_start, int search_end) {
  int mid = (L + R) >> 1;
  dp[mid][j] = -1;

  int best_index = 0;
  for(int i = search_start; i <= search_end; i++) {
    long long curr = dp[i][j - 1] + cost[i + 1][mid];
    if(curr > dp[mid][j]) {
      best_index = i;
      dp[mid][j] = curr;
    }
  }

  if(mid > L) divide_and_conquer(j, L, mid - 1, search_start, best_index);
  if(mid < R) divide_and_conquer(j, mid + 1, R, best_index, search_end);
}

int main(){
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    for(int i = 1 ; i <= N ; i++) {
      cin >> A[i];
      cost[i][i] = A[i];
    }
    for(int i = 1; i <= N; i++) {
      for(int j = i + 1; j <= N; j++) {
        cost[i][j] = cost[i][j - 1] | A[j];
      }
    }

    for(int i = 1 ; i <= N ; i++) dp[i][1] = cost[1][i];
    for(int i = 2 ; i <= K ; i++) divide_and_conquer( i , 1 , N , 1 , N);

    cout << dp[N][K] << endl;
  }
}
