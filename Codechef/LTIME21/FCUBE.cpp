// The First Cube

#include <iostream>
#include <map>

using namespace std;

#define MOD 1000000007

unsigned long long bases[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };

unsigned long long modpow(unsigned long long base, unsigned long long exp, unsigned long long M){
    base %= M;
    unsigned long long result = 1;
    while(exp > 0){
            if(exp & 1) result = (result * base) % M;
            base = (base * base) % M;
            exp >>= 1;
        }
    return result;
}

unsigned long long modmul(unsigned long long a, unsigned long long b, unsigned long long c){
    unsigned long long x = 0, y= a % c;
    while(b > 0){
      if(b % 2 == 1){
        x = (x + y) % c;
      }
      y = (y * 2) % c;
      b /= 2;
    }
    return x % c;
}

bool miller_rabin(unsigned long long N){
  unsigned long long d = N - 1;
  while(d % 2 == 0){
    d = d/2;
    for(int i = 0; i < 7; i++){
      unsigned long long a = bases[i], temp = d;
      unsigned long long x = modpow(a, temp, N);
      while(temp != (N - 1) && x != 1 && x != (N - 1)){
        x = modmul(x, x, N);
        temp *= 2;
      }
      if(x != (N - 1) && temp % 2 == 0) return false;
    }
  }

  return true;
}

bool isPrime(unsigned long long A){
  if(A < 1795265022ULL){
    for(long long i = 2; i*i <= A; i++){
      if(A % i == 0) return false;
    }
    return true;
  }
  else {
    return miller_rabin(A);
  }
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

unsigned long long pollard_rho(unsigned long long N, unsigned long long c){
  unsigned long long t = 2, h = 2, d = 1;

  while(d == 1){
    t = (modmul(t, t, N) + c) % N;
    h = (modmul(h, h, N) + c) % N;
    h = (modmul(h, h, N) + c) % N;
    d = gcd(t - h, N);
  }

  if(d == N) return pollard_rho(c, c + 1);
  else return d;
}

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    unsigned long long answer = 1;
    map<unsigned long long, unsigned long long> factor_count;
    for(int i = 0; i < N; i++){
      unsigned long long A; cin >> A;
      answer = modmul(answer, A, MOD);
      if(isPrime(A)){
        factor_count[A]++;
      }
      else {
        while(A > 1){
          if(isPrime(A)){
            factor_count[A]++;
            A = 1;
          }
          else {
            unsigned long long curr_fact = pollard_rho(A, 1);
            factor_count[curr_fact]++;
            A /= curr_fact;
          }
        }
      }
    }

    for(auto it: factor_count){
      if((it.second % 3) != 0) {
        unsigned long long t = it.first % MOD;
        for(int k = 0; k < (3 - (it.second % 3)); k++){
          answer = modmul(answer, t, MOD);
        }
      }
    }

    cout << answer << endl;
  }
}
