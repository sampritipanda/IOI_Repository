// Sums in a Triangle

#include <stdio.h>

int max(int a, int b){
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	int N, lines;
	
	scanf("%d", &N);
	
	while(N--) {
		scanf("%d", &lines);
		int triangle[lines][lines];
		int memoized[lines][lines];
		
		for(int i = 0; i < lines; i++) {
			for(int j = 0; j <= i; j++) {
				scanf("%d", &triangle[i][j]);
			}
		}
		
		for(int i = lines - 1; i >= 0; i--) {
			for(int j = 0; j <= i; j++) {	
				if(i == lines - 1) {
					memoized[i][j] = triangle[i][j];
				}
				else {
					memoized[i][j] = triangle[i][j] + max(memoized[i + 1][j], memoized[i + 1][j + 1]);
				}
			}
		}
		
		printf("%d\n", memoized[0][0]);
	}
}