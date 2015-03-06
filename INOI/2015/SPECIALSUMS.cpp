/* Sampriti Panda, 2500003, Problem 1 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long range_sum(long long B[], int i, int j){
	if(i == 0) return B[j];
	else return B[j] - B[i - 1];
}

int main() {
	int N; scanf("%d", &N);
	int A[N], B[N];

	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]); 
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	bool sub_2 = false;
	if(A[0] == B[0]) sub_2 = true;

	long long sums_B[N];
	sums_B[0] = B[0];
	for(int i = 1; i < N; i++){
		sums_B[i] = sums_B[i - 1] + B[i];
		if(A[i] != B[i]) sub_2 = false;
	}

	long long max_sum = 0;
	for(int i = 0; i < N; i++){
		max_sum = max(max_sum, (long long)A[i]);
		for(int j = i + 1; j < N; j++){
			if(j == i + 1) max_sum = max(max_sum, (long long)(A[i] + A[j]));
			else max_sum = max(max_sum, A[i] + range_sum(sums_B, i + 1, j - 1) + A[j]);
		}
		for(int j = 0; j < i; j++){
			long long curr_sum = A[i] + A[j];
			if(i < N - 1) curr_sum += range_sum(sums_B, i + 1, N - 1);
			if(j > 0) curr_sum += range_sum(sums_B, 0, j - 1);

			max_sum = max(max_sum, curr_sum);
		}
	}

	printf("%lld\n", max_sum);
}
