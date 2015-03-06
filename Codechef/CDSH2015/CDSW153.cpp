// Virat and his challenge

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long multiples(long long z, unsigned long long x, unsigned long long y){
    return ((y/z) - ((x - 1)/z));
}

int main() {
	int T; cin >> T;
	while(T--){
		vector<int> primes;
		int N; unsigned long long L, R; cin >> N >> L >> R;
		for(int i = 2; i <= N; i++){
			bool flag = true;
			for(int j = 2; j < i; j++){
				if(i % j == 0){
					flag = false;
					break;
				}
			}
			if(flag) primes.push_back(i);
		}
		
		unsigned long long ans = 0;
		int r = primes.size();
		for(int i = 1; i <= ((1<<r)-1); i++){
			long long product = 1;
			int count = 0;
			for(int j = 0; j < r; j++){
				if(i & (1 << j)) {
					product *= primes[j];
					count++;
				}
			}
			unsigned long long curr = multiples(product, L, R);
			if(count % 2 == 1) ans += curr;
			else ans -= curr;
		}
		
		cout << ans << endl;
	}
}