// Map Size

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
  long long N, M, L, R; cin >> N >> M >> L >> R;

  set<long long> N_factors, M_factors;

  for(long long i = 1; i*i <= N; i++){
    if(i > R) break;
    if(N % i != 0) continue;

    N_factors.insert(i);
    if(i >= L && i <= R) N_factors.insert(i);
    if(i != N/i && N/i >= L && N/i <= R) N_factors.insert(N/i);
  }

  for(long long i = 1; i*i <= M; i++) {
    if(i > R) break;
    if(M % i != 0) continue;

    if(i >= L && i <= R) M_factors.insert(i);
    if(i != M/i && M/i >= L && M/i <= R) M_factors.insert(M/i);
  }

  long long ans = 0;
  for(auto i: N_factors){
    for(auto j: M_factors){
      long long prod = i; prod *= j;
      if(prod < L || prod > R) continue;

      ans++;
    }
  }

  cout << ans << endl;
}
