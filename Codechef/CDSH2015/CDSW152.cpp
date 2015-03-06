// Dhoni and the beautiful strings

#include <iostream>

using namespace std;

#define MOD 1000000007

unsigned long long dp[100001];

int main() {
	int T; cin >> T;
	
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 9;
	dp[3] = 26;
	for(int i = 4; i <= 100000; i++){
		dp[i] = (3 * dp[i - 1] - dp[i - 3]) % MOD;
	}
	
	while(T--){
		int N; cin >> N;
		cout << dp[N] << endl;
	}
}