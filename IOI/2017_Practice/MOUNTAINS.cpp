#include "mountains.h"
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N;
int Y[2000];
int dp[2000][2000];
bool chk[2000][2000];  // chk[i][j] = can i see j
int calc_R[2000], calc_L[2000];

int maximum_deevs(vector<int> y) {
  N = y.size();
  for(int i = 0; i < N; i++) Y[i] = y[i];

  for(int i = 0; i < N; i++) {
    chk[i][i] = true;
    long double max_slope = -1e11;
    for(int j = i + 1; j < N; j++) {
      long double curr_slope = (Y[j] - Y[i])/(long double)(j - i);
      if(max_slope <= curr_slope) {
        chk[i][j] = chk[j][i] = true;
        max_slope = curr_slope;
      }
    }
  }

  vector<pair<int, int> > tmp;
  for(int i = 0; i < N; i++) {
    tmp.push_back({Y[i], i});
  }
  sort(tmp.begin(), tmp.end());

  for(auto it: tmp) {
    int i = it.second;

    int L = i, R = i;
    while(L > 0 && Y[L - 1] <= Y[i]) L--;
    while(R < N - 1 && Y[R + 1] < Y[i]) R++;

    memset(calc_L, 0, sizeof calc_L);
    memset(calc_R, 0, sizeof calc_R);

    int prv = i + 1;
    for(int j = i + 2; j <= R; j++) {
      if(chk[i][j]) {
        calc_R[j] += calc_R[j - 1];
        prv = j;
      }
      else {
        calc_R[j] += calc_R[prv];
        calc_R[j] += dp[prv + 1][j];
      }
    }

    prv = i - 1;
    for(int j = i - 2; j >= L; j--) {
      if(chk[i][j]) {
        calc_L[j] += calc_L[j + 1];
        prv = j;
      }
      else {
        calc_L[j] += calc_L[prv];
        calc_L[j] += dp[j][prv - 1];
      }
    }

    for(int j = L; j <= i; j++) {
      for(int k = i; k <= R; k++) {
        int left = (i == 0 ? 0 : dp[j][i - 1]), right = (i == N - 1 ? 0 : dp[i + 1][k]);
        dp[j][k] = max(left + right, calc_L[j] + 1 + calc_R[k]);
      }
    }
  }

  return dp[0][N - 1];
}
