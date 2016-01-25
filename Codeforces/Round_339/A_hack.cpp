#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  unsigned long long L, R, K; cin >> L >> R >> K;
  unsigned long long power = 1;

  while(power < L) power *= K;

  while(power <= R) {
    cout << power << endl;
    power *= K;
  }
}
