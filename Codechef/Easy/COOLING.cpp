// Cooling Pies

#include <stdio.h>
#include <algorithm>

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int main()
{
	int T; scanf("%d", &T);
	int N;
	
	while(T--){
		scanf("%d", &N);
		int pies[N], racks[N];
		
		for(int i = 0; i < N; i++) scanf("%d", &pies[i]);
		for(int i = 0; i < N; i++) scanf("%d", &racks[i]);
		
		std::sort(pies, pies + N);
		std::sort(racks, racks + N);
		
		int count = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(racks[j] >= pies[i]){
					racks[j] = -1;
					count++;
					break;
				}
			}
		}
		printf("%d\n", count);
	}
}