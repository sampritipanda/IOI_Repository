// How to Write a Message 

#include <iostream>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long modpow(long long base, long long exp){
  base %= MOD;
  long long result = 1;
  while (exp > 0) {
      if (exp & 1) result = (result * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1;
    }
  return result;
}

int main() {
  int T; cin >> T;

  while(T--){
    int N, M; cin >> N >> M;
    string X, Y; cin >> X >> Y;

    int count = 1;
    string curr = X;
    while(true){
      count++;
      for(int i = M - 1; i >= 0; i--){
        if(curr[i] == 'A') {
          curr[i] = 'B';
          break;
        }
        else curr[i] = 'A';
      }
      if(curr == Y) break;
    }
    string a; for(int i = 0; i < M; i++) a += 'A';
    string b; for(int i = 0; i < M; i++) b += 'B';
    int test = 0;
    if(X.compare(a) <= 0 && a.compare(Y) <= 0) test++;
    if(X.compare(b) <= 0 && b.compare(Y) <= 0) test++;
    long long ans = modpow(26, N);
    for(int i = 0; i < N; i++){
      if(i + M <= N) {
        ans -= count * modpow(26, N - M);
        if(N > M) ans += test * modpow(26, N - M - 1);
      }
    }
    cout << ans << endl;
  }
}
