// Random Teams

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

unsigned long long pairs(int N){
  if(N == 0) return 0;
  unsigned long long res = N;
  res = res * (N - 1);
  res /= 2;
  return res;
}

int main() {
  unsigned long long n, m; cin >> n >> m;

  if(m == 1) cout << pairs(n) << " " << pairs(n) << endl;
  else {
    unsigned long long min = pairs(n/m) * (m - (n % m)) + pairs(n/m + 1) * (n % m);
    unsigned long long max = pairs(n - (m - 1));
    cout << min << " " << max << endl;
  }
}
