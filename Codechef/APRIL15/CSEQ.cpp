// Count Sequences

#include <iostream>
#include <vector>

using namespace std;

// https://comeoncodeon.wordpress.com/2011/07/31/combination/

/* This function calculates power of p in n! */
int countFact(long long n, long long p)
{
    int k=0;
    while (n>=p)
    {
            k+=n/p;
            n/=p;
        }
    return k;
}
 
/* This function calculates (a^b)%MOD */
long long pow(long long a, long long b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
            if(b%2 == 1)
            {
                        x=(x*y);
                        if(x>MOD) x%=MOD;
                    }
            y = (y*y);
            if(y>MOD) y%=MOD;
            b /= 2;
        }
    return x;
}
 
/*  Modular Multiplicative Inverse
 *      Using Euler's Theorem
 *          a^(phi(m)) = 1 (mod m)
 *              a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long factMOD(long long n, int MOD)
{
    long long res = 1;
    while (n > 0)
    {
            for (int i=2, m=n%MOD; i<=m; i++)
                res = (res * i) % MOD;
            if ((n/=MOD)%2 > 0)
                res = MOD - res;
        }
    return res;
}
 
long long C(long long n, long long r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
                    ((InverseEuler(factMOD(r, MOD), MOD) *
                                  InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

int main(){
  int T; cin >> T;

  while(T--){
    int N, L, R; cin >> N >> L >> R;
    long long M = R - L + 1;
    int MOD = 1000003;

    cout << (C(N + M, M, MOD) - 1 + MOD) % MOD << endl;
  }
}
