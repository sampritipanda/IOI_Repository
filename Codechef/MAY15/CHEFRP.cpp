// Chef and new recipe 

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int T; cin >> T;
	
	while(T--){
		int N; cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		int total = accumulate(A.begin(), A.end(), 0);
		int minimum = *min_element(A.begin(), A.end());
		if(minimum < 2) cout << -1 << endl;
		else cout << total - minimum + 2 << endl;
	}
}