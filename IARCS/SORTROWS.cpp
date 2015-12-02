#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	A.resize(N);
	
	for(int i = 0; i < N; i++) {
		while(true) {
			int x; cin >> x;
			if(x == -1) break;
			else A[i].push_back(x);
		}
	}
	
	sort(A.begin(), A.end());
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}