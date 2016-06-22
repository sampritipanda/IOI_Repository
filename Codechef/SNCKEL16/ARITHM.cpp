#include <iostream>

using namespace std;

bool solve(long long N, long long C) {
  if(N == 1) return true;
  if((2 * C) % N > 0) return false;

  double val = 0;
  if(((2 * C)/N - (N - 1)) % 2 == 0) {
    val = (2 * C)/N - (N - 1);
  }
  else {
    val = (2 * C)/N - 2 * (N - 1);
  }

  return val/2 >= 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long N, C; cin >> N >> C;

    if(solve(N, C)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
