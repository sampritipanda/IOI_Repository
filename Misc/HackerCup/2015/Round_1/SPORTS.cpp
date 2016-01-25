// Winning at Sports

#include <iostream>

using namespace std;

#define MOD 1000000007

unsigned long long catalan[2000 + 1] = {0};

void precalc(){
  catalan[0] = 1;
  for(int i = 0; i < 2000; i++){
    for(int j = 0; j <= i; j++){
      catalan[i + 1] += catalan[j] * catalan[i - j];
      catalan[i + 1] %= MOD;
    }
  }
}

long long mod_pow(long long a, long long x, long long p) {
  //calculates a^x mod p in logarithmic time.
  long long res = 1;
  while(x > 0) {
    if( x % 2 != 0) {
      res = (res * a) % p;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return res;
}


long long count_stressfree(int A, int B){
  long long numerator = 1;
  numerator = (numerator * (A - B)) % MOD;
  for(int i = 1; i <= (A + B - 1); i++) numerator = (numerator * i) % MOD;

  long long denominator = 1;
  for (int i = 1; i <= A; i++) denominator = (denominator * i) % MOD;
  for (int i = 1; i <= B; i++) denominator = (denominator * i) % MOD;

  long long ans = (numerator * mod_pow(denominator, MOD - 2, MOD) ) % MOD;
  return ans;
}

unsigned long long count_stressful(int A, int B){
  return catalan[B];
}

int main() {
  precalc();
  int T; cin >> T;

  for(int i = 1; i <= T; i++){
    int A, B; cin >> A >> B;
    B = -B;

    cout << "Case #" << i << ": " << count_stressfree(A, B) << " " << count_stressful(A, B) << endl;
  }
}
