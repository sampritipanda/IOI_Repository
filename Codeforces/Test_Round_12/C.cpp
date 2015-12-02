// Increasing Subsequences

#include <iostream>
#include <algorithm>

using namespace std;

long long fenwick[100002];

void update(int i, long long value){
  for(; i <= 100001; i += i & (-i))
    fenwick[i] += value;
}

long long query(int i){
  long long sum = 0;
  for(; i > 0; i -= i & (-i))
    sum += fenwick[i];
  return sum;
}

int main() {
  int N, K; cin >> N >> K;
  K++;
  int A[N]; for(int i = 0; i < N; i++) cin >> A[i];

  long long dp[N][K + 1];

  for(int i = 0; i < N; i++){
    for(int p = 0; p <= K; p++){
      dp[i][p] = 0;
    }
  }

  for(int i = 0; i < N; i++) dp[i][1] = 1;

  for(int p = 2; p <= K; p++){
    for(int i = 0; i <= 100001; i++) fenwick[i] = 0;

    for(int i = 1; i < N; i++){
      update(A[i - 1] + 1, dp[i - 1][p - 1]);
      dp[i][p] = query(A[i]);
    }
  }

  long long ans = 0;
  for(int i = 0; i < N; i++){
    ans += dp[i][K];
  }

  cout << ans << endl;
}
