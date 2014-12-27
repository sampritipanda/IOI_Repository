// Enormous Input Test

#include <stdio.h>

int main()
{
	unsigned long int i;
	unsigned long int n, k;
	unsigned long int t;
	unsigned long int num = 0;
	
	scanf("%lu %lu\n", &n, &k);
	
	while(n--){
		scanf("%lu", &t);
		if(!(t % k)) num++;
	}
	
	printf("%lu\n", num);
	
	return 0;
}