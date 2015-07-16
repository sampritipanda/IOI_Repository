// Covered Path

#include <iostream>

using namespace std;

int main() {
	int v1, v2; cin >> v1 >> v2;
	int t, d; cin >> t >> d;
	int prefix[t + 1], suffix[t + 1];
	prefix[1] = v1; for(int i = 2; i <= t; i++) prefix[i] = prefix[i - 1] + d;
	suffix[t] = v2; for(int i = t - 1; i >= 1; i--) suffix[i] = suffix[i + 1] + d;
	
	int ans = 0;
	for(int i = 1; i <= t; i++){
		ans += min(prefix[i], suffix[i]);
	}
	
	cout << ans << endl;
}
