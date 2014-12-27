// Prime Palindromes

#include <stdio.h>

int is_palindrome(int num){
	int n = num;
	int rev = 0;
	while (num > 0)
	{
		int dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	return rev == n;
}

int is_prime(int num){
	int i;
    for (i=2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
	int N; scanf("%d", &N);
	
	for(int i = N; true; i++){
		if(is_palindrome(i)){
			if(is_prime(i)){
				printf("%d\n", i);
				break;
			}
		}
	}
}