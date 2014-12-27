// Repetition-free Numbers

#include <stdio.h>
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

bool repeated(int N){
  if(N == 0) return true;
  int used[10] = {0};

  while (N != 0) {
    if (N % 10 == 0 || used[N % 10]) return true;
    used[N % 10] = 1;
    N /= 10;
  }

  return false;
}

int main(){
  int N; scanf("%d", &N);
  while(repeated(N)){
    N++;
  }
  printf("%d\n", N);
}
