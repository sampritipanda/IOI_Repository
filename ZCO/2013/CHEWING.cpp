#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K = 0;

int main() {
	// Input
	int N, K;
	cin >> N >> K;
	vector<int> gum (N);
	for(int i = 0; i < N; i++) {
		cin >> gum[i];
	}
	
	sort(gum.begin(), gum.end());
	
	long long combs = 0;
	
  for(int i = 0; i < N; i++){
    long long index = lower_bound(gum.begin(), gum.end(), K - gum[i]) - gum.begin() - 1;
    if(index < i) break;
    combs += index - i;
  }
	
	cout << combs << endl;
	
	return 0;
}
