#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, B;
vector<pair<int, pair<int, int> > > V;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q; cin >> N >> Q;
  A.resize(N); B.resize(N);

  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  for(int i = 0; i < N; i++) {
    V.push_back({i, {A[i], B[i]}});
  }

  sort(V.begin(), V.end());

  while(Q--) {
    int a, b; cin >> a >> b;

    int i = lower_bound(V.begin(), V.end(), make_pair(-1, make_pair(a, b))) - V.begin();
    if(i == N) cout << -1 << endl;
    else cout << V[i].first + 1 << endl;
  }
}
