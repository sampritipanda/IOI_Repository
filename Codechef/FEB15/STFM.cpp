// Chef and Strange Formula

#include <iostream>

using namespace std;

#define LIMIT 10000001

unsigned long long facts[10000001 + 1];

void precalc(unsigned long long M){
  facts[0] = 1;
  for(unsigned long long i = 1; i < LIMIT; i++){
    facts[i] = (facts[i - 1] * i) % M;
  }
}

int main() {
  unsigned long long N, M, P;
  cin >> N >> M;
  precalc(M);

  unsigned long long sum = 0;
  for(unsigned long long i = 0; i < N; i++){
    cin >> P;
    unsigned long long curr_sum = 0;

    if(P % 2 == 0){
      curr_sum += (((P/2) % M) * ((P + 1) % M)) % M;
    }
    else {
      curr_sum += ((P % M) * (((P + 1)/2) % M)) % M;
    }
    curr_sum = (curr_sum * (P % M)) % M;

    unsigned long long curr_fac = 0;
    if((P + 1) < M){
      curr_fac = facts[P + 1];
      if(curr_fac == 0) curr_fac = M;
      curr_fac--;
    }
    else {
      curr_fac = M - 1;
    }
    sum = (((sum + curr_sum) % M) + curr_fac) % M;
  }

  cout << sum << endl;
}
