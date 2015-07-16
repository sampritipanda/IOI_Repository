// Equality

#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	
	while(T--){
		int N; cin >> N;
		long long A[N]; 
		long long sum = 0;
		for(int i = 0; i < N; i++){
			cin >> A[i];
			sum += A[i];
		}
		sum /= (N - 1);
		
		for(int i = 0; i < N; i++){
			cout << sum - A[i] << " \n"[i == (N - 1)];
		}
	}
}