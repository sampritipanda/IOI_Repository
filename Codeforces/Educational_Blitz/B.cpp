#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  long long N; cin >> N;
  long long T; cin >> T;

  double res = N;
  double curr = 1.000000011;
  while(T) {
    if(T & 1) res *= curr;
    curr *= curr;
    T >>= 1;
  }
  printf("%.8f\n", res);
}
