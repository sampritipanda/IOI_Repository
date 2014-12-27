// Ciel and Receipt

#include <stdio.h>
#include <cmath>

int main()
{
	int T; scanf("%d", &T);
	int p;
	
	while(T--){
		int count = 0;
		scanf("%d", &p);
		
		for(int i = 11; i >= 0; i--){
			int exp = pow(2, i);
			
			if(p == 0) break;
			else if(exp > p) continue;
			else {
				count += p/exp;
				p %= exp;
			}
		}
		
		printf("%d\n", count);
	}
}