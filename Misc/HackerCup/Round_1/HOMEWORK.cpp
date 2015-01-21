// Homework

#include <iostream>

using namespace std;

#define MAX_N 10000000

void sieve(int primes[], int num_multiples[]) {
  for (int i = 2; i <= MAX_N; i++) {
    if (primes[i] == 0) {
      num_multiples[i] = 1;
      int j = 2, num;
      while ( (num = j * i) <= MAX_N ) {
        primes[num] = 1;
        num_multiples[num]++;
        ++j;
      }
    }
  }
}

int main() {
  int* primes = new int[MAX_N + 1]();
  int* num_multiples = new int[MAX_N + 1]();
  sieve(primes, num_multiples);
  int T; cin >> T;

  for(int i = 1; i <= T; i++){
    int A, B, K; cin >> A >> B >> K;
    int count = 0;
    for(int i = A; i <= B; i++){
      if(num_multiples[i] == K) count++;
    }

    cout << "Case #" << i << ": " << count << endl;
  }
}
