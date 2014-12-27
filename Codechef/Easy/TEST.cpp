// Life, the Universe, and Everything

#include <stdio.h>
#include <stdlib.h>

int main()
{
	while(1) {
		int num;
		scanf("%d", &num);
		if(num == 42) exit(0);
		else printf("%d\n", num);
	};
	return 0;
}