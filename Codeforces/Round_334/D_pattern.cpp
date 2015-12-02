#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007LL

long long modpow(long long base, long long exp, long long m=MOD) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result = (result * base) % m;
    base = (base * base) % m;
    exp >>= 1;
  }

  return result;
}

int main() {
  long long P, K; cin >> P >> K;
  if(K == 0) cout << modpow(P, P - 1) << endl;
  else if(K == 1) cout << modpow(P, P) << endl;
  else if(K == P - 1) cout << modpow(P, K/2) << endl;
  else {
    for(int i = 1; i < P; i++) {
      if(modpow(K, i, P) == 1) {
        cout << modpow(P, (P - 1)/i) << endl;
        break;
      }
    }
  }
}
