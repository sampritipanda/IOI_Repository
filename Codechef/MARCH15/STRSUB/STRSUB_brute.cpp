// Count Substrings

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, K, Q; scanf("%d %d %d", &N, &K, &Q);
    char s[N + 1]; scanf("%s", s);
    int prefix_0[N], prefix_1[N];
    prefix_0[0] = (s[0] == '0');
    prefix_1[0] = (s[0] == '1');
    for(int i = 1; i < N; i++){
      prefix_0[i] = prefix_0[i - 1] + int(s[i] == '0');
      prefix_1[i] = prefix_1[i - 1] + int(s[i] == '1');
    }

    while(Q--){
      int L, R; scanf("%d %d", &L, &R);
      L--; R--;
      long long len = R - L + 1;
      // int count_0 = prefix_0[R] - (L == 0 ? 0 : prefix_0[L - 1]);
      // int count_1 = prefix_1[R] - (L == 0 ? 0 : prefix_1[L - 1]);
      // long long ans = ((R - L + 1) * (R - L + 2))/2;

      long long ans = (len * (len + 1))/2;
      for(int l = (K + 1); l <= len; l++){
        for(int i = L; i <= (R - l + 1); i++){
          int count_0 = prefix_0[i + l - 1] - (i == 0 ? 0 : prefix_0[i - 1]);
          int count_1 = prefix_1[i + l - 1] - (i == 0 ? 0 : prefix_1[i - 1]);

          if(count_0 > K || count_1 > K) ans--;
        }
      }

      printf("%lld\n", ans);
    }
  }
}

