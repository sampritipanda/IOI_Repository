// Automated Teller Machines

#include <stdio.h>

int main()
{
	double bal, amt;
	scanf("%lf %lf", &amt, &bal);
	if(amt < bal - 0.5 && (int)amt % 5 == 0)
		printf("%.2f\n", (bal - amt - 0.5));
	else
		printf("%.2f\n", bal);
		
	return 0;
}