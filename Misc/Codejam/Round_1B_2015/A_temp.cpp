#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int f1(long long int n)
{
    if (n == 0)
        return 0;
    int ans=0;
    while (n>0)
    {
        n /= 10;
        ans += 1;
    }
    return ans;
}

long long f2(long long int N, int len, int MSB)
{
    long long int ans = N - MSB*(pow(10, len-1));
    return ans;
}

long long int f3(int N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 0;
    if (N == 2)
        return 10;
    if (N >= 3)
    {
        long long ans = 10;
        ans = ans + (N-2)*9;
        for (int i = 1; i <= N-2; i++)
        {
            ans = ans + pow(10, i);
        }
        return ans;
    }
}


int main()
{
    
    //freopen("A-large.in", "r", stdin);
    //freopen("counter_culture.txt", "w", stdout);
    int t, i;
    scanf("%d",&t);
    for (i = 1; i <= t; i++)
    {
        long long int ans;
        long long int N;
        scanf("%lld",&N);
        int len = f1(N);
        long long int steps = f3(len);
        int MSB = N/pow(10, len-1);
        long long int dexMSB = f2(N, len, MSB);
        if (N <= 10)
            ans = N;

        else if (MSB == 1)
            ans = steps + dexMSB;
        else if (MSB != 1)
            ans = steps + MSB + dexMSB;
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
