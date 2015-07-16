// Chef and Balanced Strings

#include <stdio.h>
#include <string.h>
#include <unordered_map>

using namespace std;

char P[100005];
int N;
long long dp[100005];
unordered_map<long long, pair<long long, pair<long long, long long> > > m;

long long solve(int L, int R, int type){
  m.clear();
  L--; R--;
  long long ans = 0;
  int n = R - L + 1;

  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] ^ (1 << (P[L + i - 1] - 'a'));
  }
  m[dp[0]] = {1, {0, 0}};
  for(int i = 1; i <= n; i++){
    if(type == 0) {
      ans += m[dp[i]].first;
      m[dp[i]] = {m[dp[i]].first + 1, {0, 0}};
    }
    else if(type == 1){
      ans += i * m[dp[i]].first - m[dp[i]].second.first;
      m[dp[i]] = {m[dp[i]].first + 1, {m[dp[i]].second.first + i, 0}};
    }
    else {
      ans += ((long long)i) * i * m[dp[i]].first - m[dp[i]].second.first * i + m[dp[i]].second.second;
      m[dp[i]] = {m[dp[i]].first + 1, {m[dp[i]].second.first + 2*i, m[dp[i]].second.second + (long long)i*i}};
    }
  }

  return ans;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    scanf("%s", P);
    N = strlen(P);
    int Q; scanf("%d", &Q);

    long long A = 0, B = 0;
    while(Q--){
      int X, Y, type; scanf("%d %d %d", &X, &Y, &type);

      int L = ( X + A ) % N + 1;
      int R = ( Y + B ) % N + 1;
      if (L > R) {
        int T = L;
        L = R;
        R = T;
      }
      long long ans = solve(L,R,type);
      printf("%lld\n", ans);
      // printf("%d %d %d\n", L, R, type);
      A = B;
      B = ans;
    }
  }
}
