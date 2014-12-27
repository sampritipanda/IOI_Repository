#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int* length, int N) {
  int dp2[N];
  dp2[N - 1] = 1;

  if(length[N - 2] == 2) dp2[N - 2] = 1;
  else dp2[N - 2] = 2;

  for(int i = N - 3; i >= 0; i--){
    if(i + length[i] == N) dp2[i] = 1;
    else dp2[i] = 1 + std::min(dp2[i + length[i]], dp2[i + 1]);
  }
  return dp2[0];
}

int main() {
	// Input
	int N;
	cin >> N;
	vector<int> sequence (N);
	for(int i = 0; i < N; i++) {
		cin >> sequence[i];
	}

  bool dp[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j){
        dp[i][j] = true;
      }
      else {
        dp[i][j] = false;
      }
    }
  }

  for(int i = 0; i < N - 1; i++){
    if(sequence[i] == sequence[i + 1]){
      dp[i][i + 1] = true;
    }
  }

  for( int k = 3; k <= N; ++k )  {
    for( int i = 0; i < N - k + 1 ; ++i ) {
      int j = i + k - 1;

      if( dp[i+1][j-1] && sequence[i] == sequence[j] ) {
        dp[i][j] = true;
      }
    }
  }

  int length[N];

  for(int i = 0; i < N; i++){
    int maxLength = 0;
    for(int j = i; j < N; j++){
      if(dp[i][j]){
        int length = j - i + 1;
        if(length > maxLength) maxLength = length;
      }
    }
    length[i] = maxLength;
  }

  cout << solve(length, N) << endl;
}
