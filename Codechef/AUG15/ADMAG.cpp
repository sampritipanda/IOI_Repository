// Aditi and Magic Trick

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<unsigned long long> fib;
vector<unsigned long long> fib_sum;

int main() {
  fib.push_back(1); fib_sum.push_back(1);
  fib.push_back(1); fib_sum.push_back(2);

  while(*fib_sum.rbegin() <= (unsigned long long)(1e18)) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    fib_sum.push_back(*fib_sum.rbegin() + *fib.rbegin());
  }

  int T; cin >> T;

  while(T--) {
    unsigned long long N; cin >> N;

    cout << lower_bound(fib_sum.begin(), fib_sum.end(), N) - fib_sum.begin() + 1 << endl;
  }
}
