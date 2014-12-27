// Turbo Sort

#include <stdio.h>
#include <string>

int main()
{
	int T = 0;
	scanf("%d", &T);
	
	int arr[1000001] = {0};
	
	while(T--){
		int x = 0;
		scanf("%d", &x);
		arr[x]++;
	}
	
	for(int i = 0; i < 1000001; i++){
		while(arr[i]--){
			printf("%d\n", i);
		}
	}

	return 0;
}