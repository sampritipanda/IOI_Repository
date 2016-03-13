#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<long long> A[3];

int main() {
  int N, K; cin >> N >> K;

  for(int i = 0; i < K; i++) A[i].resize(N);

  for(int j = 0; j < N; j++) {
    for(int i = 0; i < K; i++) cin >> A[i][j];
  }

  long long ans = 1;
  for(int i = 0; i < K; i++) {
    sort(A[i].begin(), A[i].end());
    long long cnt = 0;
    if(N % 2 == 1) {
      cnt = 1;
    }
    else {
      cnt = (A[i][N/2] - A[i][N/2 - 1] + 1);
    }
    cnt %= MOD;
    ans *= cnt;
    ans %= MOD;
  }

  cout << ans << endl;
}
