#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for(int (i)=(s); (i)<=(t);++(i))

const int Maxn = 25;

class ABC {
public:
  string createString(int N, int K) {
    rep(i, 0, N)
      rep(j, 0, N-i) {
        int k = N - i - j;
        int maxB = 0;
        rep(r, 1, i) maxB += j+k;
        rep(r, 1, j) maxB += k;
        if (K <= maxB) {
          int diff = maxB - K;
          string ans = "";
          rep(r, 1, i) ans += 'A';
          rep(r, 1, j) ans += 'B';
          rep(r, 1, k) ans += 'C';
          int idx = N-1;
          while(diff) {
            if(!idx) idx = N-1;
            swap(ans[idx-1], ans[idx]);
            --idx;
          }
          return ans;
        }
      }
    return string("");
  }
};
