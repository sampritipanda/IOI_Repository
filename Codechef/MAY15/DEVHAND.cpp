// Devu and his three Hands

#include <iostream>

#define MOD 1000000007

using namespace std;

long long modpow(long long base, long long exp){
	base %= MOD;
	long long result = 1;
	while(exp > 0){
		if(exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

long long calc(long long N, long long K){
	long long a = 1, b = 0, c = 0;
	long long a2, b2, c2;
	for(int i = 0; i < N; i++){
		a2 = (K * a + 1) % MOD;
		b2 = (((K * b) % MOD) + ((K * (K - 1) * modpow(a, 2)) % MOD) % MOD) % MOD;
		c2 = (((K * c) % MOD) + (((K * (K - 1) * a) % MOD) * (3 * b + (((K - 2) * modpow(a, 2)) % MOD)) % MOD) % MOD) % MOD;
		
		a = a2, b = b2, c = c2;
	}
	return c;
}

int main() {
	int T; cin >> T;

	while(T--){
		long long N, K; cin >> N >> K;
		cout << calc(N, K) << endl;
	}
}
