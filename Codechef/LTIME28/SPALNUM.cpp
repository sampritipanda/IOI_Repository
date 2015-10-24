// Sum of palindromic numbers

#include <iostream>
#include <algorithm>

using namespace std;

bool is_palin(int num) {
  int N = num, rev = 0;
  while(N > 0) {
    rev = rev * 10 + (N % 10);
    N /= 10;
  }

  return (num == rev);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int L, R; cin >> L >> R;
    long long sum = 0;

    for(int i = L; i <= R; i++) {
      if(is_palin(i)) sum += i;
    }

    cout << sum << endl;
  }
}
