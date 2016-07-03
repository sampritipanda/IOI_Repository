#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100000;

bool A[N + 1];
int C[N + 1];
int sieve[N + 1];
long long P[N + 1];

int main() {
  for(int i = 1; i <= N; i++) A[i] = sieve[i] = true;

  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= N; i++) {
    if(!sieve[i]) continue;
    for(int j = i + i; j <= N; j += i) {
      sieve[j] = false;
    }
  }

  for(int i = 2; i * i <= N; i++) {
    for(int j = i * i; j <= N; j += i * i) {
      A[j] = false;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      if(A[j]) C[j] += i;
    }
  }

  for(int i = 1; i <= N; i++) {
    if(!A[i]) continue;
    int cnt = 0;
    int X = C[i];
    if(X % 2 == 0) cnt++;
    while(X % 2 == 0) X /= 2;
    for(int j = 3; j * j <= X; j += 2) {
      if(X % j == 0) cnt++;
      while(X % j == 0) X /= j;
    }
    if(X != 1) cnt++;
    if(!sieve[cnt]) A[i] = false;
  }

  for(int i = 1; i <= N; i++) {
    P[i] = P[i - 1];
    if(A[i]) P[i] += C[i];
  }

  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int L, R; cin >> L >> R;

    cout << P[R] - P[L - 1] << endl;
  }
}
