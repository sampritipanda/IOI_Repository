// Rock Paper Scissors Magic

#include <vector>
#include <string>
#include <iostream>

#define MOD 1000000007

using namespace std;

long long memo[2001][2001];

long long solve(int curr, int score){
  if(score < 0) return 0;
  if(curr == -1 && score > 0) return 0;
  if(curr == -1 && score == 0) return 1;

  if(memo[curr][score] != -1) return memo[curr][score];

  long long num_ways = 0;
  num_ways = (num_ways + solve(curr - 1, score - 1)) % MOD;  // Win
  num_ways = (num_ways + solve(curr - 1, score)) % MOD;      // Tie
  num_ways = (num_ways + solve(curr - 1, score)) % MOD;      // Lose

  memo[curr][score] = num_ways;
  return num_ways;
}

class RockPaperScissorsMagicEasy {
  public:
  int count(vector <int> card, int score) {
    for(int i = 0; i <= 2000; i++){
      for(int j = 0; j <= 2000; j++){
        memo[i][j] = -1;
      }
    }
    int N = card.size();
    return solve(N - 1, score);
  }
};

int main() {
  RockPaperScissorsMagicEasy test;
  cout << test.count({0,1,2,3,4}, 2) << endl;
}
