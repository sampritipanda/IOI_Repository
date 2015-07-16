// Chef and Prime Divisors

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


bool sieve[50000001];
vector<int> primes;

void generate_sieve() {
	for(int i = 0; i <= 50000000; i++) sieve[i] = true;
	for(int i = 2; i <= 50000000; i++){
		if(!sieve[i]) continue;
		primes.push_back(i);
		
		for(int j = i + i; j <= 50000000; j++) sieve[j] = false;
	}
}


unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	//generate_sieve();
	int T; cin >> T;
	
	while(T--){
		unsigned long long A, B; cin >> A >> B;
		unsigned long long G = gcd(A, B);
		
		if(G == 1 && B != 1) {
			cout << "No" << endl;
			continue;
		}
		if(G == B) {
			cout << "Yes" << endl;
			continue;
		}
		
		vector<unsigned long long> divisors;
		if(G % 2 == 0) divisors.push_back(2);
		while(G % 2 == 0) G /= 2;
		
		int limit = min(double(10000), sqrt(G));
		for(int i = 3; i <= limit; i++){
			if(G % i == 0) divisors.push_back(i);
			while(G % i == 0) G /= i;
		}
		if(((unsigned long long)(cbrt(G)) * (unsigned long long)(cbrt(G)) * (unsigned long long)(cbrt(G))) == G) {
			G /= (unsigned long long)(cbrt(G));
			G /= (unsigned long long)(cbrt(G));
		}
		if(((unsigned long long)(sqrt(G)) * (unsigned long long)(sqrt(G))) == G) {
			G /= (unsigned long long)(sqrt(G));
		}	

		if(G > 2) {
			divisors.push_back(G);
		}
		
		for(auto it: divisors){
			while(B % it == 0) B /= it;
		}
		
		if(B == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}