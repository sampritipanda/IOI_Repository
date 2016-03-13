#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
string A, B;
int dp[1000][1000];
int nxt[1000][1000];   // -1 = Not pos, 0 = Use A, 1 = User B, 2 = Use Both

int solve(int i, int j) {
  if(i == N && j == M) return 0;
  else if(i == N) return 1 + solve(i, j + 1);
  else if(j == M) return 1 + solve(i + 1, j);

  if(dp[i][j] != -1) return dp[i][j];

  int ans = INT_MAX/2;

  if(A[i] == B[j]) {
    if(1 + solve(i + 1, j + 1) < ans) {
      ans = 1 + solve(i + 1, j + 1);
      nxt[i][j] = 2;
    }
  }

  int ans1 = 1 + solve(i + 1, j);
  int ans2 = 1 + solve(i, j + 1);

  if(ans1 < ans2 && ans1 < ans) {
    ans = ans1; nxt[i][j] = 0;
  }
  else if(ans2 < ans1 && ans2 < ans) {
    ans = ans2; nxt[i][j] = 1;
  }
  else if(ans1 == ans2 && ans1 < ans){
    if(A[i] <= B[j]) {
      ans = ans1; nxt[i][j] = 0;
    }
    else {
      ans = ans2; nxt[i][j] = 1;
    }
  }

  return dp[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;
  cin >> A >> B;

  if(!lexicographical_compare(A.begin(), A.end(), B.begin(), B.end())) {
    swap(N, M);
    swap(A, B);
  }

  for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      dp[i][j] = -1;
      nxt[i][j] = -1;
    }
  }

  int len = solve(0, 0);

  int i = 0, j = 0;
  while(i < N && j < M) {
    if(nxt[i][j] == 0) {
      cout << A[i];
      i++;
    }
    else if(nxt[i][j] == 1) {
      cout << B[j];
      j++;
    }
    else if(nxt[i][j] == 2) {
      cout << A[i];
      i++; j++;
    }
  }

  while(i < N) cout << A[i++];
  while(j < M) cout << B[j++];

  cout << endl;
}
