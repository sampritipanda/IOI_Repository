// The Kings Factorization

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class TheKingsFactorization {
  public:
  vector<long long> getVector(long long N, vector<long long> primes) {
    vector<long long> factors;
    for(auto it = primes.begin(); it != primes.end(); it++){\
      factors.push_back(*it);
      N /= *it;
    }

    // Try Pollard Rho
    while(N % 2 == 0){
      factors.push_back(2);
      N /= 2;
    }

    for(int i = 3; i <= sqrt(N); i += 2){
      while(N % i == 0){
        factors.push_back(i);
        N /= i;
      }
    }

    if(N > 2) factors.push_back(N);

    sort(factors.begin(), factors.end());
    return factors;
  }
};

int main() {
  vector<long long> primes;
  primes.push_back(3);
  TheKingsFactorization test;
  vector<long long> t = test.getVector(999999999999999993, primes);
  for(auto it = t.begin(); it != t.end(); it++) cout << *it << endl;
}
