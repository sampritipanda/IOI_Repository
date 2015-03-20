// The Permutation Game

#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long a, long long b){
  return (a*b)/gcd(a, b);
}

class ThePermutationGameDiv2 {
  public:
  long long findMin(int N) {
    long long ans[N + 1];
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i <= N; i++){
      ans[i] = lcm(i, ans[i - 1]);
    }
    return ans[N];
  }
};

int main() {
  ThePermutationGameDiv2 test; cout << test.findMin(2) << endl;
}
