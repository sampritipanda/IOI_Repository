// Ciel and A-B Problem

#include <stdio.h>

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	
	int correct = A - B;
	int last_digit = correct % 10;
	
	if(last_digit > 1) printf("%d\n", correct - 1);
	else printf("%d\n", correct + 1);
}