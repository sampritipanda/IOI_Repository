#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int A[19];
long long dp[19][11][11][2][2];

long long solve(int i, int prv, int prv_2, int less_than, int leading) {
	if(i == -1) return 1;
	if(dp[i][prv][prv_2][less_than][leading] != -1) return dp[i][prv][prv_2][less_than][leading];
	
	long long ans = 0;
	for(int j = 0; j <= (less_than ? A[i] : 9); j++) {
		if(j == prv || j == prv_2) continue;
		
		if(leading) {
			if(j == 0) {
				ans += solve(i - 1, 10, prv, less_than & (j == A[i] ? 1 : 0), 1);
			}
			else {
				ans += solve(i - 1, j, prv, less_than & (j == A[i] ? 1 : 0), 0);
			}
		}
		else {
			ans += solve(i - 1, j, prv, less_than & (j == A[i] ? 1 : 0), 0);
		}
	}
	
	return dp[i][prv][prv_2][less_than][leading] = ans;
}

long long find_pal_free(long long X) {
	if(X == -1) return 0;
	if(X == 0) return 1;
	long long T = X; N = 0;
	while(T > 0) {
		A[N++] = T % 10;
		T /= 10;
	}
	
	memset(dp, -1LL, sizeof dp);
	return solve(N - 1, 10, 10, 1, 1);	
}

int main() {
	long long L, R; cin >> L >> R;
	
	cout <<  find_pal_free(R) - find_pal_free(L - 1) << endl;
}
