#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> X(N);
  for(int i = 0; i < N; i++) cin >> X[i];

  sort(X.begin(), X.end());
  reverse(X.begin(), X.end());

  set<int> A;
  long long ans = 0;
  for(auto x: X) {
    while(x > 0 && A.count(x) != 0) x--;
    ans += x;
    A.insert(x);
  }
  cout << ans << endl;
}
