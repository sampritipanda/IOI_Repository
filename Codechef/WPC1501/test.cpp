// Program to print all prime factors
# include <stdio.h>
# include <math.h>

// A function to print all prime factors of a given number n
void primeFactors(unsigned long long n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    unsigned long long limit = sqrt(n);
    for (unsigned long long i = 3; i <= limit; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%llu ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%llu ", n);

    printf("\n");
    return;
}

/* Driver program to test above function */
int main()
{
    unsigned long long n = 1000000000000000003ULL;
    primeFactors(n);
    return 0;
}
