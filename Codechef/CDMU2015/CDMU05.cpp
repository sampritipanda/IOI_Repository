// Exam time

#include <iostream>

using namespace std;

#define MOD 1000000007

long long answers[1000002];

int main() {
	answers[0] = 0;
	answers[1] = 0;
	answers[2] = 1;
	answers[3] = 2;
	answers[4] = 2;
	answers[5] = 3;
	for(int i = 6; i <= 1000001; i++){
		answers[i] = (answers[i - 2] + answers[i - 3]) % MOD;
	}
	
	int T; cin >> T;
	
	while(T--){
		int N; cin >> N;
		cout << answers[N + 1] << endl;
	}
}