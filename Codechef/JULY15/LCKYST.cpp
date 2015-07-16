// Na2a and lucky stone

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  for(int i = 0; i < T; i++) {
    long long N; cin >> N;
    int count_5 = 0;
    long long dup_N = N;
    while(N > 0 && N % 5 == 0) {
      count_5++;
      N /= 5;
    }
    N = dup_N;
    while(N > 0 && N % 2 == 0) {
      count_5--;
      N /= 2;
    }

    while(count_5 > 0) {
      dup_N *= 4;
      count_5 -= 2;
    }

    cout << dup_N << endl;
  }
}
