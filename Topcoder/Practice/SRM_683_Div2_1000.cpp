#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define MOD 1000000007LL

vector<vector<int> > G;
vector<long long> dp, dp2;
// dp[i] = sum for all subtrees rooted at i
// dp2[i] = number of subtrees rooted at i

void solve(int i, int p) {
  dp[i] = 1; dp2[i] = 1;
  for(auto v: G[i]) {
    if(v == p) continue;

    solve(v, i);

    dp[i] = (dp[i] * (dp2[v] + 1) + dp[v] * dp2[i]);
    dp[i] %= MOD;

    dp2[i] = (dp2[i] * (dp2[v] + 1)) % MOD;
  }
}

class SubtreesCounting {
  public:
  int sumOfSizes(int N, int a0, int b, int c, int m) {
    G.clear(); G.resize(N);
    dp.clear(); dp.resize(N);
    dp2.clear(); dp2.resize(N);

    vector<long long> A(N);
    A[0] = a0;
    for(int i = 1; i <= N - 2; i++) {
      A[i] = (b * A[i - 1] + c) % m;
    }

    for(int i = 1; i < N; i++) {
      int j = int(A[i - 1] % ((long long)i));
      G[i].push_back(j);
      G[j].push_back(i);
    }

    solve(0, -1);
    long long ans = 0;
    for(int i = 0; i < N; i++) ans = (ans + dp[i]) % MOD;
    return int(ans);
  }
};

int main() {
  SubtreesCounting test;
  cout << test.sumOfSizes(3, 1, 1, 1, 1) << endl;
}
