#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> z0, z1;
vector<int> dp;

int dfs(int i) {
  if(dp[i] != -1) return dp[i];

  dp[i] = 0;

  int ans = 0;
  ans = max(ans, 1 + dfs(z0[i]));
  ans = max(ans, 1 + dfs(z1[i]));

  return dp[i] = ans;
}

class Autohamil {
  public:
  string check(vector <int> temp_z0, vector <int> temp_z1) {
    z0 = temp_z0;
    z1 = temp_z1;
    int N = z0.size();

    dp.resize(N, -1);

    return (dfs(0) == N ? "Exists" : "Does not exist");
  }
};

int main() {
  Autohamil test;
  cout << test.check({1, 2, 0, 3}, {3, 2, 0, 3}) << endl;
}
