// Packaging Cupcakes

#include <stdio.h>

int main()
{
	int T; scanf("%d", &T);
	int N;
	
	while(T--){
		scanf("%d", &N);
		
		printf("%d\n", N/2 + 1);
	}
}