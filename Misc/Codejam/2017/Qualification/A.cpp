#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int sum[1000];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    string S; cin >> S;
    int N = S.length();
    int K; cin >> K;
    bool pos = true;
    int cnt = 0;

    memset(sum, 0, sizeof sum);

    for(int i = 0; i < N; i++) {
      if(S[i] == '+') {
        if(sum[i] == 1) {
          if(i >= N - (K - 1)) {
            pos = false;
            break;
          }
          else {
            for(int j = i; j < i + K; j++) sum[j] ^= 1;
            cnt++;
          }
        }
      }
      else {
        if(sum[i] == 0) {
          if(i >= N - (K - 1)) {
            pos = false;
            break;
          }
          else {
            for(int j = i; j < i + K; j++) sum[j] ^= 1;
            cnt++;
          }
        }
      }
    }

    if(!pos) {
      cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    }
    else {
      cout << "Case #" << t << ": " << cnt << endl;
    }
  }
}
