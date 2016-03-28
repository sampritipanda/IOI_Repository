#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());

  int Q; cin >> Q;

  while(Q--) {
    int a, b; cin >> a >> b;
    int cnt = upper_bound(A.begin(), A.end(), b) - lower_bound(A.begin(), A.end(), a);
    cout << cnt << endl;
  }
}
