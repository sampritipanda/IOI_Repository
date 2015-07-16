#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool sieve[5000010];
long long ans[5000010];
vector<int> primes;

int main() {
  for(int i = 0; i <= 5000000; i++) sieve[i] = true;
  sieve[1] = false;
  for(int i = 2; i <= 5000000; i++) {
    if(!sieve[i]) continue;
    sieve[i] = true;
    primes.push_back(i);
    for(int j = i+i; j <= 5000000; j += i) sieve[j] = false;
  }
  ans[1] = 0;
  for(int i = 2; i <= 5000000; i++){
    if(sieve[i]) ans[i] = ans[i - 1] + 1;
    else {
      ans[i] = ans[i - 1];
      int tmp = i;
      while(!sieve[tmp]) {
        for(auto it: primes){
          if(tmp % it == 0) {
            ans[i]++;
            tmp /= it;
            break;
          }
        }
      }
      if(sieve[tmp]) ans[i]++;
    }
  }

  int T; scanf("%d", &T);
  while(T--) {
    int a, b; scanf("%d %d", &a, &b);
    printf("%d\n", ans[a] - ans[b]);
  }
}
