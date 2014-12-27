#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Input
	int N, K;
	cin >> N >> K;
	vector<int> sequence (N);
	for(int i = 0; i < N; i++) {
		cin >> sequence[i];
	}
	
	sort(sequence.begin(), sequence.end());
	
	long long pairs = 0;
	
  for(int i = 0; i < N; i++){
    long long index = lower_bound(sequence.begin(), sequence.end(), K + sequence[i]) - sequence.begin();
    if(index < i) break;
    pairs += N - index;
  }
	
	cout << pairs << endl;
	
	return 0;
}
