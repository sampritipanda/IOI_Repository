#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 1000000007

using namespace std;

// 0000000  =  7
// 0001000  =  6
// 0001010  =  4, 1
// 1001010  =  2, 1, 1
// 1001110  =  2, 1
// 1101110  =  1, 1

int N, K;
map<vector<int>, long long> dp;

int cnt(vector<int>& A) {
  if(A.size() == 1 && A[0] == N) return 0;
}

long long solve(vector<int> A) {
  if(A.size() == 0) return 1;
  if(A.size() > K) return 0;
  if(dp.count(A) > 0) return dp[A];

  long long ans = 0;
  for(int i = 0; i < A.size(); i++) {
    vector<int> T = A;
    if(A[i] == 1) {
      T.erase(T.begin() + i);
      ans += solve(T);
    }
    else {
      T[i] -= 1;
      sort(T.begin(), T.end());
      ans += 2 * solve(T);

      for(int j = 2; j <= A[i] - 1; j++) {
        T = A;
        T.erase(T.begin() + i);
        T.push_back(j - 1);
        T.push_back(A[i] - j);
        sort(T.begin(), T.end());
        ans += solve(T);
      }
    }
    ans %= MOD;
  }
  return dp[A] = ans;
}

int main() {
  cin >> N >> K;

  cout << (N * solve({N - 1})) % MOD << endl;
}
