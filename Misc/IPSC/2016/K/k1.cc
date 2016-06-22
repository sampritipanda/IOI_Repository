#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

long long f1(long long n) {
    return (-n*n*n + 947*n*n + 20647474747LL*n + 47) / 20000000047LL;
}

long long f2(long long n) {
    return (-n*n + 2084747*n + 47) / 2494747;
}

long long f3(long long n) {
    return (-n*n*n + 19647*n*n + 23254474747LL*n - 25384747*(n%97)*n + 47 ) / 25382294747LL;
}

void sort_helper(vector<unsigned> &A, int lo, int hi) {
    long long n = hi - lo;
    if (n <= 2) {
        if (n == 2 && A[lo] > A[lo+1]) swap( A[lo], A[lo+1] );
        return;
    }
    long long a = median( 0, n-1, f1(n) );
    long long b = median( 0, n-1, f2(n) );
    long long c = median( 0, n-1, f3(n) );
    sort_helper( A, lo, lo+a );
    sort_helper( A, hi-b, hi );
    sort_helper( A, lo, lo+c );
}

// this is the main function
void k1_sort(vector<unsigned> &A) {
    sort_helper( A, 0, A.size() );
}

int main() {
  int N; cin >> N;
  vector<unsigned> A;

  for(int i = 0; i < N; i++) {
    unsigned x; cin >> x;
    A.push_back(x);
  }

  k1_sort(A);

  cout << is_sorted(A.begin(), A.end()) << endl;
}
