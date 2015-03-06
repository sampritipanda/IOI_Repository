// Dhoni is in a Dilemma

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	int T; cin >> T;
	
	while(T--){
		int N, Z; cin >> N >> Z;
		long long O[N]; for(int i = 0; i < N; i++) cin >> O[i];
		long long prefix[N]; prefix[0] = O[0];
		for(int i = 1; i < N; i++) prefix[i] = prefix[i - 1] ^ O[i];
		
		long long powerplay = -1, runs = LLONG_MAX;
		for(int i = 0; i <= (N - Z); i++){
			long long curr = prefix[i + Z - 1];
			if(i > 0) curr ^= prefix[i - 1];
			if(curr < runs) {
				runs = curr;
				powerplay = i;
			}
		}
		
		cout << powerplay + 1 << endl;
	}
}