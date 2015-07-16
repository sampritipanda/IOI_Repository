// Unequal

#include <iostream>
#include <algorithm>

#define MAX 100000000

using namespace std;

int N, K;
int A[1000100];
int memo[1000100][4];
int next_ans[1000100][4];

int solve(int i, int curr){
	if(i == N) return 0;
	if(memo[i][min(curr, 3)] != -1) return memo[i][min(curr, 3)];
	
	int min_ans = MAX;
	for(int m = 0; m < min(K, 4); m++){
    int j = m;
    if(m == 3) j = A[i + 1];
		if(curr == j) continue;
		int curr_ans = ((i == (N - 1) || A[i + 1] == j) ? 0 : 1) + solve(i + 1, j);
		if(curr_ans < min_ans){
			min_ans = curr_ans;
			next_ans[i][min(curr, 3)] = j;
		}
	}
	
	memo[i][min(curr, 3)] = min_ans;
	return min_ans;
}

int main() {
	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> A[i];
	
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= 3; j++){
			memo[i][j] = -1;
		}
	}
	
	int ans = MAX;
	int start = MAX;
	for(int m = 0; m < min(K, 4); m++){
    int j = m;
    if(j == 3) j = A[0];
		int curr_ans = (A[0] == j ? 0 : 1) + solve(0, j);
		if(curr_ans < ans){
			ans = curr_ans;
			start = j;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < N; i++){
		cout << start << " ";
		start = next_ans[i][min(start, 3)];
	}
	cout << endl;
}
