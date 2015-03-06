// Mice and Food Consumption

#include <iostream>
#include <algorithm>

using namespace std;

long long dp[100001];

int main() {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= 100000; i++){
		dp[i] = min(dp[i/2], dp[i - i/2]);
	}
	
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		cout << dp[N] << endl;
	}
}