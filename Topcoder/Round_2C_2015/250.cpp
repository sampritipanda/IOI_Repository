// Yet Another Card Game

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> petr, snuke;
int N;

int dp[51][51][101][3];

int solve(int i, int j, int top_card, int player) {
  if(i >= N && j >= N) return 0;

  if(dp[i][j][top_card][player] != -1) return dp[i][j][top_card][player];

  int ans = 0;
  if(player == 1) {
    if(i < N && petr[i] > top_card) {
      int new_top_card = petr[i];
      int new_i = i + 1;//max(i, int(upper_bound(petr.begin(), petr.end(), new_top_card) - petr.begin()));
      int new_j = j;//max(j, int(upper_bound(snuke.begin(), snuke.end(), new_top_card) - snuke.begin()));
      ans = max(ans, 1 + solve(new_i, new_j, new_top_card, 2));
    }
    ans = max(ans, solve(i + 1, j, top_card, 2));
  }
  else {
    if(j < N && snuke[j] > top_card) {
      int new_top_card = snuke[j];
      int new_i = i;//max(i, int(upper_bound(petr.begin(), petr.end(), new_top_card) - petr.begin()));
      int new_j = j + 1;//max(j, int(upper_bound(snuke.begin(), snuke.end(), new_top_card) - snuke.begin()));
      ans = max(ans, 1 + solve(new_i, new_j, new_top_card, 1));
    }
    ans = max(ans, solve(i, j + 1, top_card, 1));
  }

  dp[i][j][top_card][player] = ans;
  return ans;
}

class YetAnotherCardGame {
  public:
  int maxCards(vector <int> p, vector <int> s) {
    for(int i = 0; i <= 50; i++) {
      for(int j = 0; j <= 50; j++) {
        for(int k = 0; k <= 100; k++) {
          dp[i][j][k][1] = -1;
          dp[i][j][k][2] = -1;
        }
      }
    }

    petr = p, snuke = s;
    sort(petr.begin(), petr.end());
    sort(snuke.begin(), snuke.end());

    N = petr.size();

    int ans = solve(0, 0, 0, 1);
    return ans;
  }
};

int main() {
  YetAnotherCardGame test;
  cout << test.maxCards({1, 4, 6, 7, 3}, {1, 7, 1, 5, 7}) << endl;
}
