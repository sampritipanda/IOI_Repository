// Counter Culture

#include <iostream>
#include <algorithm>

#define INF 10000000000000000LL

using namespace std;

long long dp[100000005];

long long reverse(long long in) {
  long long out = 0;
  while(in){
    out *= 10;
    out += in % 10;
    in /= 10;
  }
  return out;
}

int main() {
  for(int i = 0; i <= 100000000; i++) dp[i] = INF;
  dp[1] = 1;
  for(int i = 1; i < 1000000; i++){
    int rev = reverse(i);
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    dp[rev] = min(dp[rev], dp[i] + 1);
  }

  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    long long N; cin >> N;
    cout << "Case #" << t << ": " << dp[N] << endl;
  }

  long long max_a = 1, max_a_i = 1;;
  for(int i = 1; i < 1000000; i++) {
    if(dp[i] > max_a){
      max_a = dp[i];
      max_a_i = i;
    }
  }
  cout << max_a_i << ": " << max_a << endl;
}
