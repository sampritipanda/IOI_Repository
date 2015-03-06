/* Sampriti Panda, 2500003, Problem 2 */

#include <stdio.h>
#include <cmath>
#include <set>

using namespace std;

set<int> factors;
int powers[150001];
bool primes[150001];

void factorise(int N){
  factors.clear();
	for(int i = 1; i*i <= N; i++){
		if(N % i == 0) {
      factors.insert(i);
      factors.insert(N/i);
    }
	}
  factors.erase(N);
}

void calc(int M){
	powers[0] = 1;
	for(int i = 1; i <= 150000; i++){
		powers[i] = (powers[i - 1] * 2) % M;
	}
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	calc(M);
	for(int i = 0; i <= N; i++) primes[i] = true;
	factorise(N);
	long long dp[N + 1];
  dp[1] = 2;
  for(int i = 2; i <= N; i++){
    factorise(i);
    dp[i] = powers[i];
    for(set<int>::iterator it = factors.begin(); it != factors.end(); it++){
      dp[i] -= dp[*it];
      dp[i] = (dp[i] + M) % M;
    }
  }
  printf("%lld\n", dp[N]);
}
