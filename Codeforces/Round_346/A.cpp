#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N, A, B; cin >> N >> A >> B;
  A--;

  A += B;

  while(A < N) A += N;
  A %= N;

  cout << A + 1 << endl;
}
