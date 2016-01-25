#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

#define MOD 1000000007

int N;
string A;
int nxt[700];
long long dp[700][700][3][3];

// i, j = range, k = color of left neighbor, l = color of right neighbour
// 0 = uncoloured, 1 = red, 2 = blue
long long solve(int i, int j, int k, int l) {
  if(i + 1 == j) return 1;
  if(dp[i][j][k][l] != -1) return dp[i][j][k][l];

  long long ans = 0;
  if(nxt[i] == j) {
  }
}

int main() {
  cin >> A;
  N = A.length();
  stack<int> S;
  for(int i = 0; i < N; i++) {
    if(A[i] == '(') S.push(i);
    else {
      int t = S.top(); S.pop();
      nxt[t] = i;
      nxt[i] = t;
    }
  }
}
