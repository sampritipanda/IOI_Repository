// Bytelandian gold coins

#include <stdio.h>
#include <map>

using namespace std;

map<long long int, long long int> memo;

long long int calc(long long int N){
  if(N/2 + N/3 + N/4 >= N){
    if(memo.find(N/2) == memo.end()){
      memo[N/2] = calc(N/2);
    }
    if(memo.find(N/3) == memo.end()){
      memo[N/3] = calc(N/3);
    }
    if(memo.find(N/4) == memo.end()){
      memo[N/4] = calc(N/4);
    }
    return memo[N/2] + memo[N/3] + memo[N/4];
  }
  else {
    return N;
  }
}

int main() {
  long long N;

  while(scanf("%lld", &N) != EOF){
    printf("%lld\n", calc(N));
  }
}
