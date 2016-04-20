#include <iostream>
#include <algorithm>

using namespace std;

long long F[100001];
long long P[100001];

int main() {
  for(int i = 1; i <= 100000; i++) {
    for(int j = 1; j*j <= i; j++) {
      if(i % j == 0) {
        if(j % 2 == 1) F[i] += j;
        if(i/j != j && i/j % 2 == 1) F[i] += i/j;
      }
    }
  }

  for(int i = 1; i <= 100000; i++) P[i] = P[i - 1] + F[i];

  int T; cin >> T;

  while(T--) {
    int L, R; cin >> L >> R;

    cout << P[R] - P[L - 1] << endl;
  }
}
