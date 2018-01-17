#include <bits/stdc++.h>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    vector<long long> A(3);
    scanf("%lld %lld %lld", &A[0],&A[1],&A[2]);
    sort(A.begin(),A.end());
    long long ans = ceil(sqrt((A[0] + A[1]) * (A[0] + A[1]) + A[2]*A[2]))+0.000000001;
    printf("%lld\n", ans);
  }
}
