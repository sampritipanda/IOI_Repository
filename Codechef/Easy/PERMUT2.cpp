// Ambiguous Permutations

#include <stdio.h>

int main()
{
	int N;
	while(scanf("%d", &N)){
		if(N == 0) break;
		int nums[N + 1];
		bool ambiguous = true;
		
		for(int i = 1; i <= N; i++) scanf("%d", &nums[i]);
		
		for(int i = 1; i <= N; i++) {
			if(nums[nums[i]] != i){
				ambiguous = false;
				break;
			}
		}
		
		if(ambiguous) {
			printf("ambiguous\n");
		}
		else {
			printf("not ambiguous\n");
		}
	}
}