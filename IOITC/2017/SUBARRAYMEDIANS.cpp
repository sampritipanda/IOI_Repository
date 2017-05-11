#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100000;
const int BLOCK_SIZE = 300;
const int OFFSET = BLOCK_SIZE;

int N;
int A[MAX_N + 2];
int rev_A[MAX_N + 2];
int B[MAX_N + 2];
int P[MAX_N/BLOCK_SIZE + 1][BLOCK_SIZE];
int F[MAX_N/BLOCK_SIZE + 1][OFFSET * 2 + 1];

void recalculate(int id) {
	int L = BLOCK_SIZE * id, R = min(L + BLOCK_SIZE - 1, N);
	P[id][0] = B[L];
	for(int i = L + 1; i <= R; i++) {
		P[id][i - L] = P[id][(i - 1) - L] + B[i];
	}
	memset(F[id], 0, sizeof F[id]);
	for(int i = L; i <= R; i++) {
		F[id][P[id][i - L] + OFFSET]++;
	}
}

inline int get_pref_sum(int R) {
	if(R < 0) return 0;
	int sum = 0;
	for(int id = 0; id <= R/BLOCK_SIZE; id++) {
		int curr_L = id * BLOCK_SIZE, curr_R = curr_L + BLOCK_SIZE - 1;
		if(R < curr_R) {
			for(int i = curr_L; i <= R; i++) sum += B[i];
		}
		else {
			sum += P[id][BLOCK_SIZE - 1];
		}
	}
	return sum;
}

// Count number of prefix sums with value x in range [L..R]
int count_pref(int L, int R, int x) {
	x -= get_pref_sum(L/BLOCK_SIZE * BLOCK_SIZE - 1);
	int ans = 0;
	for(int i = L/BLOCK_SIZE; i <= R/BLOCK_SIZE; i++) {
		int curr_L = i * BLOCK_SIZE, curr_R = curr_L + BLOCK_SIZE - 1;
		if(L > curr_L) {
			for(int j = L; j <= min(R, curr_R); j++) {
				if(P[i][j - curr_L] == x) ans++;
			}
		}
		else if(R < curr_R) {
			for(int j = curr_L; j <= R; j++) {
				if(P[i][j - curr_L] == x) ans++;
			}
		}
		else {
			if(x >= -BLOCK_SIZE && x <= BLOCK_SIZE) ans += F[i][x + OFFSET];
		}
		x -= P[i][BLOCK_SIZE - 1];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		rev_A[A[i]] = i;
	}
	A[N + 1] = N + 1;
	rev_A[N + 1] = N + 1;
	
	for(int i = 1; i <= N; i++) B[i] = -1;
	
	int BLOCK_CNT = N/BLOCK_SIZE + 1;
	for(int i = 0; i < BLOCK_CNT; i++) recalculate(i);
	
	long long ans = 0;
	for(int i = N; i >= 1; i--) {
		B[rev_A[i + 1]] = 1;
		B[rev_A[i]] = 0;
		recalculate(rev_A[i]/BLOCK_SIZE);
		if(rev_A[i]/BLOCK_SIZE != rev_A[i + 1]/BLOCK_SIZE) {
			recalculate(rev_A[i + 1]/BLOCK_SIZE);
		}
		
		int pref_sum_prev = get_pref_sum(rev_A[i] - 1);
		int pref_sum_curr = pref_sum_prev + B[rev_A[i]];
		
		ans += count_pref(rev_A[i], N, pref_sum_prev);
		ans += count_pref(rev_A[i], N, pref_sum_prev + 1);
		
		ans += count_pref(0, rev_A[i] - 2, pref_sum_curr);
		ans += count_pref(0, rev_A[i] - 2, pref_sum_curr - 1);
	}
	cout << ans << endl;
}
