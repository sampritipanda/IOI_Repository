#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define MOD 1000000007

int A[100001];
long long C[100001];
set<int> V;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    V.clear();

    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      V.insert(A[i]);
      C[i] = 0;
    }

    int val = A[1], cnt = 1;
    for(int i = 2; i <= N; i++) {
      if(A[i] == val) cnt++;
      else {
        C[val] += ((1LL * cnt) * (cnt + 1))/2;
        C[val] %= MOD;
        val = A[i];
        cnt = 1;
      }
    }
    C[val] += ((1LL * cnt) * (cnt + 1))/2;

    long long ans = 1;
    for(int x: V) {
      ans = (ans * C[x]) % MOD;
    }
    cout << ans << endl;
  }
}
