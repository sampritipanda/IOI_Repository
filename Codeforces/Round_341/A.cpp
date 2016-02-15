#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);

  int N; cin >> N;
  long long ans = 0;
  vector<int> A;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x % 2 == 0) ans += x;
    else {
      A.push_back(x);
    }
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  for(int i = 0; i < int(A.size())/2 * 2; i++) {
    ans += A[i];
  }

  cout << ans << endl;
}
