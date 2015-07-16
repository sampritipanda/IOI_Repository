#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N, K; cin >> N >> K;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
      int a; cin >> a;
      if(a % K == 0) continue;
      if(a/K == 0) ans += K - a;
      else ans += min(K - (a % K), a % K);
    }
    cout << ans << endl;
  }
}
