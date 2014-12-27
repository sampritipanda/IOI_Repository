// Let us construct palindrome

#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

bool check(char* x)
{
  int mistakes = 0;
  int N = strlen(x);

  for (int l = 0, r = N - 1; l < r; l++, r--) {
    if (x[l] != x[r]) {
      if (mistakes >= 1) return false;

      bool condition1 = x[l + 1] == x[r];
      bool condition2 = x[l] == x[r - 1];
      if (condition1 && condition2) {
        // Do Nothing
      } else if (condition1) {
        l++;
        mistakes++;
      } else if (condition2) {
        r--;
        mistakes++;
      } else {
        return false;
      }
    }
  }

  return (mistakes >= 0 && mistakes <= 1);
}

int main(){
  int T; scanf("%d", &T);
  char str[100000];

  while(T--){
    scanf("%s", str);

    if(check(str)){
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }
}
