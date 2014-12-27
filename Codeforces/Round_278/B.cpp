// Candy Boxes

#include <stdio.h>
#include <cmath>

bool int_double(double x){
  return (trunc(x) == x);
}

int main(){
  int n; scanf("%d", &n);
  int a[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  if(n < 2){
    printf("NO\n");
  }
  else if(n == 2){
    int x_3 = 4*a[0] - a[1];
    double x_4 = 3.0*(a[1] + x_3)/4.0;
    if(int_double(x_4)){
      printf("YES\n");
      printf("%d\n", (int)x_3);
      printf("%d\n", (int)x_4);
    }
    else {
      printf("NO\n");
    }

  }
  else if(n == 3){
    double x_4 = 3.0*(a[1] + a[2])/4.0;
    if(int_double(x_4)){
      printf("YES\n");
      printf("%d\n", (int)x_4);
    }
    else {
      printf("NO\n");
    }
  }
  else {
    printf("YES\n");
  }
}
