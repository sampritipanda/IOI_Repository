// Yet Another Number Game

#include <stdio.h>

int main()
{
	int times; scanf("%d", &times);
	int N;
	
	while(times--) {
		scanf("%d", &N);
		
		if(N % 2 == 0) printf("ALICE\n");
		else printf("BOB\n");
	}
}