// Holes in the Text

#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d", &T);
	
	while(T--){
		char str[100];
		scanf("%s", str);
		
		int count = 0;
		
		for(int i = 0; i < strlen(str); i++) {
			if(str[i]=='B') count += 2;
			else if(str[i] == 'P' || str[i] == 'O' || str[i] == 'A' || str[i] == 'D' || str[i] == 'R' || str[i] == 'Q') count++;
		}
		
		printf("%d\n", count);
	}

	return 0;
}