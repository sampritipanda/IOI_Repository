// Chef and Strings

#include <stdio.h>
#include <cmath>
#include <cstring>
#include <unordered_map>

#define MAX_N 1000000

using namespace std;

long long char_pairs[4][4][MAX_N + 1];
long long char_counts[4][MAX_N + 1];
char chars[4] = { 'c', 'h', 'e', 'f' };

int positions(char a){
  switch(a) {
      case 'c':
        return 0;
        break;
      case 'h':
        return 1;
        break;
      case 'e':
        return 2;
        break;
      case 'f':
        return 3;
        break;
      default:
        return -1;
    }
}

void constructPrefixSums(char P[], int N){
  for(int i = 0; i < 4; i++){
    char_counts[i][0] = (P[0] == chars[i]);
    for(int j = 1; j < N; j++){
      char_counts[i][j] = char_counts[i][j - 1] + (P[j] == chars[i]);
    }
  }

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(i == j) continue;

      char_pairs[i][j][0] = 0;
      int start_count = (P[0] == chars[i]);
      for(int k = 1; k < N; k++){
        char_pairs[i][j][k] = char_pairs[i][j][k - 1];
        if(P[k] == chars[i]) start_count++;
        else if(P[k] == chars[j]) char_pairs[i][j][k] += start_count;
      }
    }
  }
}

int main() {
  char P[MAX_N + 1]; scanf("%s", P);
  int N = strlen(P);
  constructPrefixSums(P, N);

  int Q; scanf(" %d", &Q);
  while(Q--){
    char a, b;
    int L, R;
    scanf(" %c %c %d %d", &a, &b, &L, &R);
    L--; R--;

    long long ans = 0;
    if(L == 0) ans = char_pairs[positions(a)][positions(b)][R];
    else {
      ans += char_pairs[positions(a)][positions(b)][R] - char_pairs[positions(a)][positions(b)][L - 1];
      ans -= (char_counts[positions(b)][R] - char_counts[positions(b)][L - 1]) * (char_counts[positions(a)][L - 1]);
    }
    printf("%lld\n", ans);
  }
}
