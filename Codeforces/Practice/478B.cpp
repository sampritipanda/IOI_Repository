// Random Teams

#include <iostream>

using namespace std;

unsigned long long pairs(int N){
  if(N == 0) return 0;
  unsigned long long res = N;
  res = res * (N - 1);
  res /= 2;
  return res;
}

int main() {
  int n, m; cin >> n >> m;

  if(m == 1) cout << pairs(n) << " " << pairs(n) << endl;
  else {
    unsigned long long min = n/2;
    unsigned long long max = pairs(n - (m - 1));
    cout << min << " " << max << endl;
  }
}
