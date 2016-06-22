#include <algorithm>
#include <vector>
using namespace std;

// this is just a standard pseudorandom generator
struct PRNG {
    long long seed;
    PRNG(long long seed) : seed(seed) {}

    long long _random() {
        long long M = 2147483647, A = 16807;
        long long Q = M/A, R = M%A;
        seed = A*(seed%Q) - R*(seed/Q);
        if (seed <= 0) seed += M;
        return seed;
    }

    long long randint(int lo, int hi) {
        return lo + _random() % (hi-lo);
    }
};

long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

void modify(vector<unsigned> &A, int x, int y, bool magic) {
    if (A[x] > A[y] || !magic) swap( A[x], A[y] );
}

// this is the main function
void k2_sort(vector<unsigned> &A) {
    PRNG generator(589);
    
    int N = A.size();
    int L = 1;
    while ((1<<L) < N) ++L;
    int lo = (N - (1<<L)) / 2;
   
    for (int superphase=0; superphase<2; ++superphase) {
        for (int phase=1; phase<=L; ++phase) {
            for (int subphase=phase; subphase>=1; --subphase) {
                if (phase == L && subphase == L) {
                    for (int i=0; i < (1<<(L-1)); ++i) {
                        int x = lo+i, y = lo+(1<<L)-1-i;
                        if (x >= 0 && y < N) modify( A, x, y, L*superphase+phase >= 2*(L-1) );
                    }
                }
                for (int block=0; block<(1<<(L-subphase)); ++block) {
                    int xlo  = median( 0, N, lo + (block << subphase) );
                    int xmed = median( 0, N, lo + (block << subphase) + (1<<(subphase-1)) );
                    int xhi  = median( 0, N, lo + (block << subphase) + (1<<subphase) );
                    if (xlo == xmed || xmed == xhi) continue;
                    for (int comparison=0; comparison<521; ++comparison) {
                        int x = generator.randint(xlo,xmed);
                        int y = generator.randint(xmed,xhi);
                        modify( A, x, y, L*superphase+phase >= 2*(L-1) );
                    }
                }
            }
        }
    }
}
