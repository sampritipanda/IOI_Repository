#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int A, B; cin >> A >> B;
  int N = A, M = B;

  int max_a, max_b;
  for(max_a = 1; true; max_a++) {
    if(max_a % 6 == 0) {
      if(N > M) N--;
      else M--;
    }
    else if(max_a % 3 == 0) {
      if(M > 0) M--;
    }
    else if(max_a % 2 == 0) {
      if(N > 0) N--;
    }

    if(N + M == 0) break;
  }

  cout << max_a << endl;
}
