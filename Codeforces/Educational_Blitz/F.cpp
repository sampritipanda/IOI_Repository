#include <iostream>

using namespace std;

int main() {
  long long N; cin >> N;

  long long ans1 = N * (N - 1) * (N - 2) * (N - 3) * (N - 4);
  long long ans2 = N * (N - 1) * (N - 2) * (N - 3) * (N - 4) * (N - 5);
  long long ans3 = (N * (N - 1) * (N - 2) * (N - 3) * (N - 4) * (N - 5))/720 * (N - 6);

  cout << ans1/120 + ans2/720 + ans3/7 << endl;
}
