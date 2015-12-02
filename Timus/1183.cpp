#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[100][100];
int ans[100][100];

int main() {
  string S; cin >> S;
  int N = S.length();

  for(int i = 0; i < N; i++) {
    dp[i][i] = 1;
  }
}
