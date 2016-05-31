#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string S;
bool dp[200][200];
int dp_min[201], dp_max[201];
int nx_min[201], nx_max[201];

int main() {
  cin >> S;
  N = S.length();

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
    if(S[i] == S[i + 1]){
      dp[i][i + 1] = true;
    }
  }

  for(int k = 3; k <= N; k++)  {
    for(int i = 0; i < N - k + 1 ; i++) {
      int j = i + k - 1;

      if(dp[i + 1][j - 1] && S[i] == S[j] ) {
        dp[i][j] = true;
      }
    }
  }

  dp_min[N] = dp_max[N] = 0;

  for(int i = N - 1; i >= 0; i--) {
    dp_min[i] = INT_MAX/2;
    dp_max[i] = 0;

    nx_min[i] = nx_max[i] = -1;

    for(int j = i + 1; j < N; j++) {
      if((j - i + 1) % 2 == 1) continue;
      if(!dp[i][j]) continue;

      if(1 + dp_min[j + 1] < dp_min[i]) {
        dp_min[i] = 1 + dp_min[j + 1];
        nx_min[i] = j + 1;
      }
      if(1 + dp_max[j + 1] > dp_max[i]) {
        dp_max[i] = 1 + dp_max[j + 1];
        nx_max[i] = j + 1;
      }
    }
  }

  if(dp_min[0] == INT_MAX/2 || dp_max[0] == 0) {
    cout << "NIE" << endl;
  }
  else {
    int i = 0;
    while(i != N) {
      for(int j = i; j < nx_min[i]; j++) cout << S[j];
      if(nx_min[i] < N) cout << " ";
      else cout << endl;
      i = nx_min[i];
    }

    i = 0;
    while(i != N) {
      for(int j = i; j < nx_max[i]; j++) cout << S[j];
      if(nx_max[i] < N) cout << " ";
      else cout << endl;
      i = nx_max[i];
    }
  }
}
