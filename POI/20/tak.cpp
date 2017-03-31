#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long M, D; int N; cin >> M >> D >> N;
  multiset<long long> X;
  for(int i = 0; i < N; i++) {
    long long x; cin >> x;
    X.insert(x);
  }

  if(*X.rbegin() < (M - D)) {
    cout << 0 << endl;
    return 0;
  }
  if(*X.rbegin() - D >= M) {
    cout << 1 << endl;
    return 0;
  }
  long long saved = *X.lower_bound(M - D);
  X.erase(X.find(saved));

  long long curr = 0;
  int ans = 0;
  while(curr < D) {
    if(X.size() == 0) {
      break;
    }
    long long x = *X.rbegin(); X.erase(X.find(x));
    x -= (D - curr);
    if(x > 0) curr += x;
    ans++;
    if(curr < M) {
      if(curr + saved - abs(D - curr) >= M) {
        curr += saved - abs(D - curr);
        ans++;
        break;
      }
    }
  }
  if(curr >= M) cout << ans << endl;
  else cout << 0 << endl;
}
