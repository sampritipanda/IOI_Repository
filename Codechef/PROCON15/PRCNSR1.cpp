#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long N, K; cin >> N >> K;

    if(N > (K * (K + 1))/2) cout << -1 << endl;
    else {
      double lo = 0, hi = K;
      for(int msa = 0; msa <= 200; msa++) {
        double mid = lo + (hi - lo)/2;

        double sum = (K * (K + 1))/2 - ((mid - 1) * (mid))/2;
        if(sum < N) {
          hi = mid;
        }
        else {
          lo = mid;
        }
      }
      cout << (long long)(lo) - 1 << endl;
    }
  }
}
