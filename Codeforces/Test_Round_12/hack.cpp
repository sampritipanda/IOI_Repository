#include <iostream>

using namespace std;

int main() {
  long long k, a, b; cin >> k >> a >> b;
  long long sol = 0;

  if(a % k != 0) {
    if(a < 0) a -= a % k; else a += k - a % k;
  }
  if(b % k != 0) {
    if(b < 0) b += -k - b % k; else b -= b % k;
  }

  if(b >= a) sol = (b - a)/k + 1;
  cout << sol << endl;

}
