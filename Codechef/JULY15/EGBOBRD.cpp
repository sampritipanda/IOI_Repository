// Bread

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; long long K; cin >> N >> K;
    long long A[N]; for(int i = 0; i < N; i++) cin >> A[i];

    long long packets = 0;
    long long curr_bread = 0;
    for(int i = 0; i < N; i++) {
      if(curr_bread > 0) {
        A[i] -= curr_bread;
        curr_bread = 0;
      }

      long long packets_required = ceil(double(A[i])/K);
      packets += packets_required;
      curr_bread = packets_required * K - A[i];
      curr_bread = max(0LL, curr_bread - 1);
    }

    cout << packets << endl;
  }
}
