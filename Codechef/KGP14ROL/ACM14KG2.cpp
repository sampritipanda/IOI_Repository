// The last cracker

#include <stdio.h>

int main(){
	int T; scanf("%d", &T);
	int N, a, M;
	
	while(T--){
		scanf("%d %d %d", &N, &a, &M);
		int ans = (a + M) % N;
		if(ans == 0) ans = N;
		printf("%d\n", ans);
	}
}