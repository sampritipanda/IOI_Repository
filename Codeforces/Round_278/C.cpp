#include <iostream>
#include <algorithm>

using namespace std;

/*

   prefix_seq = ->(a) { a.size.times.map { |i| a[0..i].reduce(1, :*) % a.size} }
   a = (1..n).to_a.permutation.select { |x| prefix_seq.(x).sort == (0...n).to_a }

*/

long long modpow(long long base, long long exp, long long mod) {
  long long res = 1;
  while(exp > 0) {
    if(exp & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res;
}

int main() {
  int N; cin >> N;

  if(N == 1) {
    cout << "YES" << endl;
    cout << 1 << endl;
  }
  else if(N == 4) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 3 << endl;
    cout << 2 << endl;
    cout << 4 << endl;
  }
  else {
    bool prime = true;
    for(int i = 2; i*i <= N; i++) {
      if(N % i == 0) {
        prime = false;
        break;
      }
    }

    if(prime) {
      cout << "YES" << endl;
      cout << 1 << endl;
      for(int i = 2; i <= N - 1; i++) {
        cout << (i * modpow(i - 1, N - 2, N)) % N << endl;
      }
      cout << N << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}
