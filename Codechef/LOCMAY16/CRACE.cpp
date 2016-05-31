#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  dp[0] = 0;
  for(int i = 1; i <= 1000000; i++) {
    if(!dp[i - 1]) dp[i] = 1;
    if(i >= 3 && !dp[i - 3]) dp[i] = 1;
    if(i >= 5 && !dp[i - 5]) dp[i] = 1;
  }

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    if(dp[N]) cout << "JENNY" << endl;
    else cout << "JACK" << endl;
  }
}
