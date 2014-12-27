// Giga Tower

#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

bool lucky(long long int N){
  N = std::abs(N);
  if(N == 0) return false;

  while (N != 0) {
    if (N % 10 == 8) return true;
    N /= 10;
  }

  return false;
}

int main(){
  long long int N; std::cin >> N; 
  long long int new_N = N;
  new_N++;
  while(!lucky(new_N)){
    new_N++;
  }
  std::cout << new_N - N << std::endl;
}
