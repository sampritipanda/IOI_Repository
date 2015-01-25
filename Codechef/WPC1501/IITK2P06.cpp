// Let us play with even and odd numbers 

#include <stdio.h>

using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

bool check_ratio(int e, int o){
  int g = gcd(e, o);
  return (e/g == 2 && o/g == 3);
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int e, o; scanf("%d %d", &e, &o);

    double ratio = 2/3.0;
    int count = 0;
    if(e/double(o) < ratio){
      while(e/double(o) < ratio){
        e++;o--;
        count++;
      }
      if(check_ratio(e, o)){
        printf("%d\n", count);
      }
      else {
        printf("-1\n");
      }
    }
    else {
      while(e/double(o) > ratio){
        e--;o++;
        count++;
      }
      if(check_ratio(e, o)){
        printf("%d\n", count);
      }
      else {
        printf("-1\n");
      }
    }
  }
}
