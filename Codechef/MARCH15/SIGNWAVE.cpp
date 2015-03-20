// Sign Wave

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int S, C, K; cin >> S >> C >> K;

    if(C == 0) {
      if(K > S) cout << 0 << endl;
      else {
        unsigned long long ans = 1ULL << (S - K + 1);
        ans++;
        cout << ans << endl;
      }
    }
    else if(K == 1){
      if(S > C) cout << (1ULL << S) + 1ULL << endl;
      else if(S == C) {
        cout << (1ULL << S) + (1ULL << C) + (S > 0 ? 1 : 0) << endl;
      }
      else {
        unsigned long long ans = (1ULL << (C + 1)) - 2;
        if(S >= 1) ans += 3;
        cout << ans << endl;
      }
    }
    else {
      unsigned long long ans = 0;
      if(S >= K) {
        ans += (1ULL << (S - K + 1)) + 1;
        if(S > (S - K + 1)){
          if(C >= (S - K + 1)) ans += (1ULL << (S - K + 1));
        }
      }
      cout << ans << endl;
    }
  }
}
