// Count Substrings

#include <stdio.h>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, K, Q; scanf("%d %d %d", &N, &K, &Q);
    char s[N + 1]; scanf("%s", s);
    long long prefix_0[N], prefix_1[N];
    long long prefix_ans[N], others[N], prefix_others[N];
    prefix_0[0] = (s[0] == '0');
    prefix_1[0] = (s[0] == '1');
    for(int i = 1; i < N; i++){
      prefix_0[i] = prefix_0[i - 1] + int(s[i] == '0');
      prefix_1[i] = prefix_1[i - 1] + int(s[i] == '1');
    }

    prefix_ans[0] = 1;
    others[0] = prefix_others[0] = 0;
    for(int i = 1; i < N; i++){
      prefix_ans[i] = prefix_ans[i - 1];
      long long t_0 = -1, t_1 = -1;

      if((prefix_0[i] - K) > 0) t_0 = (prefix_0 + i) - lower_bound(prefix_0, prefix_0 + i, prefix_0[i] - K);
      else t_0 = i + 1;
      if((prefix_1[i] - K) > 0) t_1 = (prefix_1 + i) - lower_bound(prefix_1, prefix_1 + i, prefix_1[i] - K);
      else t_1 = i + 1;

      prefix_ans[i] += min(t_0, t_1);
      others[i] = max(min(t_0, t_1) - 1, 0LL);
      prefix_others[i] = prefix_others[i - 1] + others[i];
    }

    // for(int i = 0; i < N; i++) printf("%lld ", prefix_ans[i]);
    // printf("\n");
    // for(int i = 0; i < N; i++) printf("%lld ", prefix_others[i]);
    // printf("\n");

    while(Q--){
      int L, R; scanf("%d %d", &L, &R);
      L--; R--;

      long long ans = 0;
      if(L == 0) ans = prefix_ans[R];
      else {
        ans += prefix_ans[R];
        ans -= prefix_ans[L - 1];

        // long long count = 0;
        // for(int i = L; i <= R; i++){
        //   if(i - L >= others[i]) break;
        //   count++;
        //   ans -= others[i];
        // }
        // count--;
        // ans += (count * (count + 1))/2;

        long long imin = L, imax = R;
        while(imin < imax){
          long long imid = (imin+imax)>>1;
          if(!(imid < imax)) return 0;
          if(others[imid] <= (imid - L)) {
            imax = imid;
          }
          else {
            imin = imid + 1;
          }
        }
        if(!(imax == imin && others[imin] <= (imin - L))) imin = R + 1;

        ans -= prefix_others[imin - 1];
        if(L > 0) ans += prefix_others[L - 1];
        ans += ((imin - L - 1) * (imin - L))/2;
      }

      printf("%lld\n", ans);
    }
  }
}
