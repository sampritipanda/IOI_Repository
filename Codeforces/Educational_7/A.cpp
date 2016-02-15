#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  long long N; cin >> N;

  long long M = floor((sqrt(8*N - 7) - 1)/2);
  long long ans = N - (M * (M + 1))/2;

  cout << ans << endl;
}
