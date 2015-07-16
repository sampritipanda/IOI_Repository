// Polycarpus' Dice

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long N, s; cin >> N >> s;
	long long sum = 0;
	long long A[N]; 
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	
	for(int i = 0; i < N; i++){
		long long remain = min(A[i], s - (N - 1)) - max(s - (sum - A[i]), 1LL) + 1;
		cout << A[i] - remain << " ";
	}
	cout << endl;
}