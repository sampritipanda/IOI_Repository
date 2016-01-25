// The Price is Correct

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> A, P;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    A.clear(); P.clear();

    int N; cin >> N;
    long long price; cin >> price;

    A.resize(N); P.resize(N);

    for(int i = 0; i < N; i++) cin >> A[i];
    P[0] = A[0]; for(int i = 1; i < N; i++) P[i] = P[i - 1] + A[i];

    long long sum = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
      ans += upper_bound(P.begin(), P.end(), sum + price) - (P.begin() + i);
      sum += A[i];
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
