// The First Cube

#include <iostream>
#include <map>

using namespace std;

#define MOD 1000000007

bool isPrime(unsigned long long A){
  for(int i = 2; i*i <= A; i++){
    if(A % i == 0) return false;
  }
  return true;
}

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    unsigned long long answer = 1;
    for(int i = 0; i < N; i++){
      unsigned long long A; cin >> A;
      answer = (answer * (A % MOD)) % MOD;
      if(isPrime(A)){
        A %= MOD;
        answer = (answer * A) % MOD;
        answer = (answer * A) % MOD;
      }
      else {
        map<unsigned long long, unsigned long long> factor_count;
        while (A % 2 == 0) {
          factor_count[2]++;
          A = A/2;
        }
        for (unsigned long long i = 3; i*i <= A; i += 2) {
          while (A % i == 0) {
            factor_count[i]++;
            A = A/i;
          }
        }
        if (A > 2) factor_count[A]++;

        for(auto it: factor_count){
          if((it.second % 3) != 0) {
            unsigned long long t = it.first % MOD;
            for(int k = 0; k < (3 - (it.second % 3)); k++){
              answer = (answer * t) % MOD;
            }
          }
        }
      }
    }

    cout << answer << endl;
  }
}
