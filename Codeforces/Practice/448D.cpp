// Multiplication Table

#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

long long N, M, K;

bool check(long long x) {
  long long cnt = 0;
  for(int i = 1; i <= M; i++) {
    cnt += min((x - 1)/i, N);
  }
  return cnt < K;
}

int main() {
  cin >> N >> M >> K;

  long long L = 1, R = N * M + 1;
  while(L < R) {
    long long mid = L + (R - L)/2;

    if(check(mid)) {
      L = mid + 1;
    }
    else {
      R = mid;
    }
  }

  cout << L - 1 << endl;
}
