// Double Strings

#include <stdio.h>

int main()
{
	int N; scanf("%d", &N);
	int t;
	
	while(N--){
		scanf("%d", &t);
		if(t % 2 == 0) printf("%d\n", t);
		else printf("%d\n", t - 1);
	}
}