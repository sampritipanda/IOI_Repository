// Wormholes

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

vector<pair<int, int> > C;
vector<int> A, B;

int main(){
  int N, X, Y; cin >> N >> X >> Y;
  C.clear();
  A.resize(X); B.resize(Y);

  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    C.push_back({x, y});
  }

  for(int i = 0; i < X; i++) cin >> A[i];
  for(int i = 0; i < Y; i++) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans = INT_MAX;
  for(int i = 0; i < N; i++) {
    int x = C[i].first, y = C[i].second;
    int a = upper_bound(A.begin(), A.end(), x) - A.begin(); a--;
    int b = lower_bound(B.begin(), B.end(), y) - B.begin();

    if(!(a >= 0 && a <= X - 1 && b >= 0 && b <= Y - 1 && A[a] <= x && B[b] >= y)) continue;
    else ans = min(ans, B[b] - A[a] + 1);
  }

  assert(ans > 0);
  cout << ans << endl;
}
