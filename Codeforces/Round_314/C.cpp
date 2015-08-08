// Geometric Progression

#include <iostream>
#include <map>

using namespace std;

#define MOD 1000000007

long long A[200001];
map<long long, int> count, previous;

int main() {
  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) count[A[i]]++;

  long long ans = 0;
  if(K == 1) {
    for(auto it: count) {
      long long occ = it.second;
      ans += (occ * (occ - 1) * (occ - 2))/6;
    }
  }
  else {
    for(int i = 0; i < N; i++) {
      if(A[i] % K == 0) {
        long long next_el_cnt = count[A[i] * K];
        long long prev_el_cnt = previous[A[i]/K];
        ans += next_el_cnt * prev_el_cnt;
      }

      count[A[i]]--;
      previous[A[i]]++;
    }
  }

  cout << ans << endl;
}
