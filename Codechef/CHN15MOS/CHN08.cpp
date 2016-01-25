#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

int mod(long long X) {
  while(X < 0) X += MOD;
  X %= MOD;
  cout << X << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long A, B, N; cin >> A >> B >> N;

    if(N % 6 == 1) mod(A);
    else if(N % 6 == 2) mod(B);
    else if(N % 6 == 3) mod(B - A);
    else if(N % 6 == 4) mod(-A);
    else if(N % 6 == 5) mod(-B);
    else if(N % 6 == 0) mod(A - B);
  }
}
