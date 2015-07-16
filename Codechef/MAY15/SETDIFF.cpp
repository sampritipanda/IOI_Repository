// Set Difference

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long modpow(long long base, long long exp){
  base %= MOD;
  long long result = 1;
  while (exp > 0) {
      if (exp & 1) result = (result * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1;
    }
  return result;
}

// http://stackoverflow.com/a/20975702/1466095
long long modmul(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    } 

    long long a2 = modmul(a, b / 2);

    if ((b & 1) == 0) {
        return (a2 + a2) % MOD;
    } else {
        return ((a % MOD) + (a2 + a2)) % MOD;
    }
}

int main() {
	int T; scanf("%d", &T);
	
	while(T--){
		int N; scanf("%d", &N);
		int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);;
		sort(A, A + N);
		long long prefix[N], suffix[N]; 
		prefix[0] = A[0];
		for(int i = 1; i < N; i++) prefix[i] = prefix[i - 1] + A[i];
		suffix[N - 1] = A[N - 1];
		for(int i = (N - 2); i >= 0; i--) suffix[i] = suffix[i + 1] + A[i];
		
		long long ans = 0;
		for(int len = 1; len < N; len++){
			ans += modmul(((suffix[len] - prefix[N - len - 1]) + MOD) % MOD, modpow(2, len - 1));
			ans %= MOD;
		}
		
		printf("%lld\n", ans);
	}
}