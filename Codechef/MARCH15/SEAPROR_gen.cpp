#include <stdio.h>

/* ------------------ start here ---------------------*/
unsigned X; // we assume that unsigned is a 32bit integer type

void srand1(unsigned S){
  X = S;
}

unsigned nextInteger1(void){
  X = X * 1103515245 + 12345;
  return (X / 65536) % 32768;
}

void generator1(int N, unsigned S, int A[]){
  srand1(S);
  for(int i=1;i<=N;i++){
    A[i] = nextInteger1() % 2; 
  }
}
/* ------------------ end here -----------------------*/

/* ------------------ start here ---------------------*/
unsigned x, y, z, w; // we assume that unsigned is a 32bit integer type

void srand2(unsigned S){
  x = S;
  y = x * S;
  z = y * S;
  w = z * S;
}

unsigned nextInteger2(void){
  unsigned t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}

void generator2(int N, unsigned S, int A[]){
  srand2(S);
  for(int i=1;i<=N;i++){
    A[i] = nextInteger2() % 2; 
  }
}
/* ------------------ end here -----------------------*/

int main() {
  unsigned S; int gen_type, N; scanf("%d %d %u", &gen_type, &N, &S);
  int A[N + 1];
  if(gen_type == 1){
    generator1(N, S, A);
  }
  else {
    generator2(N, S, A);
  }

  for(int i = 1; i <= N; i++) printf("%d", A[i]);
  printf("\n");
}
