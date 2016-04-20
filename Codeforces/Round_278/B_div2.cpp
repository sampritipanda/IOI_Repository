// Candy Boxes

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

double median(vector<int> A) {
  sort(A.begin(), A.end());
  return double(A[2] + A[1])/2;
}

double mean(vector<int> A) {
  return double(A[0] + A[1] + A[2] + A[3])/4;
}

double range(vector<int> A) {
  sort(A.begin(), A.end());
  return double(A[3] - A[0]);
}

int main(){
  int n; scanf("%d", &n);
  int a[n];

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  if(n == 0) {
    printf("YES\n");
    printf("1\n");
    printf("1\n");
    printf("3\n");
    printf("3\n");
  }
  else if(n == 1) {
    printf("YES\n");
    printf("%d\n", a[0]);
    printf("%d\n", 3*a[0]);
    printf("%d\n", 3*a[0]);
  }
  else if(n == 2){
    bool xizt = false;
    for(int i = 1; i <= 2000; i++) {
      for(int j = 1; j <= 2000; j++) {
        if(i == 3 && j == 3) {
          bool x = true;
        }
        vector<int> curr = {a[0], a[1], i, j};
        if(range(curr) == median(curr) && median(curr) == mean(curr)) {
          xizt = true;
          printf("YES\n");
          printf("%d\n", i);
          printf("%d\n", j);
          break;
        }
      }
      if(xizt) break;
    }
    if(!xizt) printf("NO\n");
  }
  else if(n == 3){
    bool xizt = false;
    for(int i = 1; i <= 2000; i++) {
      vector<int> curr = {a[0], a[1], a[2], i};
      if(range(curr) == median(curr) && median(curr) == mean(curr)) {
        xizt = true;
        printf("YES\n");
        printf("%d\n", i);
        break;
      }
    }
    if(!xizt) printf("NO\n");
  }
  else {
    vector<int> curr = {a[0], a[1], a[2], a[3]};
    if(range(curr) == median(curr) && median(curr) == mean(curr)) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }
}
