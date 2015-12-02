#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K = 0;

int main() {
	int N, K; cin >> N >> K;
	vector<int> gum (N);

	for(int i = 0; i < N; i++) {
		cin >> gum[i];
	}

	sort(gum.begin(), gum.end());

	long long ans = 0;

  for(int i = 0; i < N; i++){
    if(gum[i] >= K) break;

    int j = lower_bound(gum.begin() + i, gum.end(), K - gum[i]) - (gum.begin() + i); j--;
    if(j > 0) ans += j;
  }

	cout << ans << endl;

	return 0;
}
