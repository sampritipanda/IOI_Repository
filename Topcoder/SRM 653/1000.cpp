// Singing

#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> pitch;
int memo[2010][2010];

int calc(int a_i, int b_i) {
  int next = max(a_i, b_i) + 1;
  if(next == pitch.size()) return 0;

  if(memo[a_i][b_i] != -1) return memo[a_i][b_i];

  memo[a_i][b_i] = min( calc(next, b_i) + (a_i > 0 ? abs(pitch[next] - pitch[a_i]) : 0),
                        calc(a_i, next) + (b_i > 0 ? abs(pitch[next] - pitch[b_i]) : 0) );

  return memo[a_i][b_i];
}

class SingingEasy {
  public:
  int solve(vector <int> p) {
    pitch.clear();
    pitch.push_back(-1);
    for(auto it: p) pitch.push_back(it);

    for(int i = 0; i < 2010; i++){
      for(int j = 0; j < 2010; j++){
        memo[i][j] = -1;
      }
    }
    return calc(0, 0);
  }
};

int main() {
  SingingEasy test;
  cout << test.solve({1,3,8,12,13}) << endl;
}

