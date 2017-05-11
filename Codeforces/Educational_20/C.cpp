#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long N, K; cin >> N >> K;

  if(K > 1000000000LL) {
    cout << -1 << endl;
    return 0;
  }

  long long min_sum = (K * (K + 1))/2;
  vector<long long> ans;

  vector<long long> divisors;
  for(long long i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      divisors.push_back(i);
      divisors.push_back(N/i);
    }
  }
  sort(divisors.begin(), divisors.end());
  reverse(divisors.begin(), divisors.end());

  for(long long x: divisors) {
    if(min_sum <= N/x) {
      for(int i = 1; i <= K; i++) ans.push_back(i);
      ans[K - 1] += N/x - min_sum;
      for(int i = 0; i < K; i++) cout << ans[i] * x << " "; cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
