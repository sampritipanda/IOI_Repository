// Fox and Souvenir

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class FoxAndSouvenirTheNext {
  public:
  string ableToSplit(vector <int> value) {
    int sum = 0;
    for(auto it: value) sum += it;
    int N = value.size();

    if((N % 2) == 1 || (sum % 2) == 1) return "Impossible";

    sum /= 2;
    int K = N/2;
    bool dp[sum + 1][N + 1];
    int size[sum + 1][N + 1];
    for(int i = 0; i <= N; i++) {
      dp[0][i] = true;
      size[0][i] = 0;
    }
    for(int i = 1; i <= sum; i++) {
      dp[sum][0] = false;
      size[sum][0] = -1;
    }

    for(int i = 0; i <= sum; i++){
      for(int j = 0; j <= N; j++){
        dp[i][j] = dp[i][j - 1];
        size[i][j] = size[i][j - 1];
        if(i >= value[j - 1]){
          if(dp[i - value[j - 1]][j - 1]){
            dp[i][j] = true;
            size[i][j]++;
          }
        }
      }
    }

    if(dp[sum][N] && size[sum][N] == K) return "Possible";
    else return "Impossible";
  }
};

