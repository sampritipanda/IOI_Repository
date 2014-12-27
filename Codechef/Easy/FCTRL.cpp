// Factorial

#include <stdio.h>
#include <cmath>

int main()
{
	unsigned long int T, N;
	scanf("%lu\n", &T);
	
	while(T--){
		scanf("%lu\n", &N);
		int zeroes = 0;
		int loops = (int)floor(log(N)/log(5));
		for(int i = 1; i <= loops; i++){
			zeroes += (int)floor(N/pow(5, i));
		}
		printf("%d\n", zeroes);
	}
	
	
	return 0;
}