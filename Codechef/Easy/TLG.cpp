// The Lead Game

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int W, L;
	
	int s_i = 0, t_i = 0;
	int diff, tmp_w;
	
	scanf("%d", &N);
	
	while(N--) {
		int c_i, d_i;
		scanf("%d %d", &c_i, &d_i);
		s_i += c_i;
		t_i += d_i;
		
		if (s_i > t_i) {
			tmp_w = 1;
			diff = s_i - t_i;
		}
		else {
			tmp_w = 2;
			diff = t_i - s_i;
		}
		
		if (diff > L) {
			L = diff;
			W = tmp_w;
		}
	}
	
	printf("%d %d", W, L);
}
