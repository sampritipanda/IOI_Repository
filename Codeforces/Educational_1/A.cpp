#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;
    long long twopower = log2(N);
    long long sum1 = (N * (N + 1))/2;
    long long sum2 = 1; for(int i = 1; i <= twopower + 1; i++) sum2 *= 2;
    sum2 -= 1;
    cout << sum1 - 2 * sum2 << endl;
  }
}
