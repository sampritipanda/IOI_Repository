// Random Pancake Stack

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int D[255];
double dp[255][255];

class RandomPancakeStack {
  public:
  double expectedDeliciousness(vector <int> d) {
    int n = d.size();
    for(int i = 0; i < n; i++) D[i + 1] = d[i];

    for(int i = 1; i <= n; i++) dp[i][1] = D[i];

    for(int i = 2; i <= n; i++) {
      for(int j = 2; j <= i; j++){
        dp[i][j] = 0.0;
        for(int k = 1; k < i; k++) dp[i][j] += dp[k][j-1]/(n-j+1);
      }
    }

    double ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) ans += dp[i][j]/n;
    }
    return ans;
  }
};
