#include "paint.h"

#include <cstring>
#include <string>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

string S;
vector<int> A;
int N, K;
int dp[2][101][200000];  // dp[k][j][i] = is it possible to have valid string for i...N with clues j...K and current character (k=0|black or 1|white)
int pref[2][200000];

inline int get_sum(int i, int L, int R) {
  if(L == 0) return pref[i][R];
  return pref[i][R] - pref[i][L - 1];
}

int solve(int i, int j, int k) {
  if(i == N) return (j == K);
  if(dp[k][j][i] != -1) return dp[k][j][i];

  int ans = 0;
  if(k == 0) {
    if(S[i] != '_' && j < K) {
      if(get_sum(1, i, i + A[j] - 1) == 0 && i + A[j] <= N) {
        ans = solve(i + A[j], j + 1, 1);
      }
    }
  }
  else {
    if(S[i] != 'X') ans = solve(i + 1, j, 0) | solve(i + 1, j, 1);
  }
  return dp[k][j][i] = ans;
}

string solve_puzzle(string _S, vector<int> _A) {
  S = _S;
  A = _A;
  N = S.length();
  K = A.size();

  memset(pref, 0, sizeof pref);
  if(S[0] == 'X') pref[0][0]++;
  else if(S[0] == '_') pref[0][1]++;
  for(int i = 1; i < N; i++) {
    pref[0][i] = pref[0][i - 1];
    pref[1][i] = pref[1][i - 1];
    if(S[i] == 'X') pref[0][i]++;
    else if(S[i] == '_') pref[1][i]++;
  }

  memset(dp, -1, sizeof dp);
  solve(0, 0, 0);
  solve(0, 0, 1);

  string ans = "";
  int ptr = -1;
  for(int i = 0; i < N; i++) {
    bool white_pos = false;
    for(int j = 0; j <= K; j++) {
      if(dp[0][j][i] == 1) ptr = max(ptr, i + A[j] - 1);
      if(dp[1][j][i] == 1) white_pos = true;
    }
    bool black_pos = (i <= ptr);
    if(black_pos && white_pos) ans += '?';
    else if(black_pos) ans += 'X';
    else if(white_pos) ans += '_';
    else assert(false);
  }
  return ans;
}
