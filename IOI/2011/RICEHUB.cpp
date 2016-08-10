#include <cstdio>
#include <algorithm>

using namespace std;

inline int scan(){
  register char c = getchar_unlocked();
  int x = 0;
  while(c<'0'||c>'9'){
    c=getchar_unlocked();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar_unlocked();
  }
  return x;
}

inline long long scanll(){
  register char c = getchar_unlocked();
  long long x = 0;
  while(c<'0'||c>'9'){
    c=getchar_unlocked();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar_unlocked();
  }
  return x;
}

int X[100001];

int main() {
  int R = scan(), L = scan(); long long B = scanll();
  for(int i = 1; i <= R; i++) X[i] = scan();

  int ans = 0;
  int i = 1, j = 0;
  for(int k = 1; k <= R; k++) {
    B -= 1LL * (k - i) * (X[k] - X[k - 1]);
    B += 1LL * (j - k + 1) * (X[k] - X[k - 1]);
    while(B < 0) {
      B += X[k] - X[i];
      i++;
    }
    while(j < R) {
      if(B < X[j + 1] - X[k]) break;
      B -= X[j + 1] - X[k];
      j++;
    }
    while(true) {
      if(i == k || j == R) break;
      if(X[k] - X[i] >= X[j + 1] - X[k]) {
        B += X[k] - X[i];
        i++;
        j++;
        B -= X[j] - X[k];
        while(j < R) {
          if(B < X[j + 1] - X[k]) break;
          B -= X[j + 1] - X[k];
          j++;
        }
      }
      else break;
    }
    while(i > 1) {
      if(B < X[k] - X[i - 1]) break;
      B -= X[k] - X[i - 1];
      i--;
    }
    ans = max(ans, j - i + 1);
  }

  printf("%d\n", ans);
}
