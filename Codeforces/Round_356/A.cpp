#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

bool prime(int i) {
  if(i == 1) return false;
  for(int j = 2; j * j <= i; j++) {
    if(i % j == 0) return false;
  }
  return true;
}

int CNT;

bool check(int i) {
  CNT++;
  assert(CNT <= 20);
  assert(i <= 100);
  printf("%d\n", i);
  fflush(stdout);
  char X[10];
  scanf(" %s", X);
  if(X[0] == 'y') return true;
  return false;
}

int main() {
  CNT = 0;
  int x = -1;
  for(int i = 1; i <= 13; i++) {
    if(!prime(i)) continue;

    if(check(i)) {
      x = i;
      break;
    }
  }

  if(x == -1) printf("prime\n");
  else if(x * x <= 100 && check(x * x)) printf("composite\n");
  else {
    bool pos = false;
    for(int i = x + 1; i <= 100/x; i++) {
      if(!prime(i)) continue;

      if(check(i)) {
        pos = true;
        break;
      }
    }
    if(pos) {
      printf("composite\n");
    }
    else {
      printf("prime\n");
    }
  }
  fflush(stdout);
}
