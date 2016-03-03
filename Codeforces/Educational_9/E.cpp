#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

set<int> A_temp;
vector<int> A;
int dp[1000001];

queue<int> Q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    A_temp.insert(a);
  }
  for(auto it: A_temp) A.push_back(it);
  N = A.size();

  int base = A[0] * K;
  for(int i = N - 1; i >= 0; i--) A[i] -= A[0];
  int maxsum = A[N - 1] * K;

  for(int i = 0; i <= 1000000; i++) dp[i] = -1;

  Q.push(0);
  dp[0] = 0;

  while(!Q.empty()) {
    int tot = Q.front(); Q.pop();

    if(dp[tot] >= K) break;

    for(auto it: A) {
      if(dp[tot + it] == -1) {  // ==> If Not visited yet
        dp[tot + it] = dp[tot] + 1;
        Q.push(tot + it);
      }
    }
  }

  for(int i = 0; i <= maxsum; i++) {
    if(dp[i] != -1) cout << base + i << " ";
  }
  cout << endl;
}
