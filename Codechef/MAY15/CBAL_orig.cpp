// Chef and Balanced Strings

#include <stdio.h>
#include <string.h>

using namespace std;

char P[100005];
int N;
int freq[26];

long long pow(int base, int exp){
  long long result = 1;
  while(exp--) result *= base;
  return result;
}

int solve(int L, int R, int type){
  L--; R--;
  long long ans = 0;
  for(int len = 2; len <= (R - L + 1); len += 2){
    for(int i = L; (i + len - 1) <= R; i++){
      memset(freq, 0, sizeof freq);
      for(int j = i; j <= (i + len - 1); j++) freq[P[j] - 'a']++;

      bool possible = true;
      for(int k = 0; k < 26; k++){
        if(freq[k] & 1){
          possible = false; break;
        }
      }
      if(possible) {
        // for(int j = i; j <= (i + len - 1); j++) printf("%c", P[j]);
        // printf("\n");
        ans += pow(len, type);
      }
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
