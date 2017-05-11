#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

long long A[1000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int T; cin >> T;
	
	while(T--) {
		int N; cin >> N;
		for(int i = 1; i <= N; i++) cin >> A[i];
		
		long long ans = LLONG_MIN/2;
		stack<long long> S;
		S.push(A[1]);
		for(int i = 2; i <= N; i++) {
			while(!S.empty() && S.top() > A[i]) S.pop();
			if(!S.empty()) {
				ans = max(ans, (A[i] | S.top()) * (A[i] | S.top()) - (A[i] & S.top()) * (A[i] & S.top()));
			}
			S.push(A[i]);
		}
		
		while(!S.empty()) S.pop();
		S.push(A[N]);
		for(int i = N - 1; i >= 1; i--) {
			while(!S.empty() && S.top() > A[i]) S.pop();
			if(!S.empty()) {
				ans = max(ans, (A[i] | S.top()) * (A[i] | S.top()) - (A[i] & S.top()) * (A[i] & S.top()));
			}
			S.push(A[i]);
		}
		
		cout << ans << endl;
	}
}
