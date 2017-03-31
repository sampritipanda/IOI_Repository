#include <iostream>
#include <algorithm>

using namespace std;

bool A[10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Z; cin >> N >> M >> Z;

  for(int i = N; i <= Z; i += N) A[i] = true;

  int ans = 0;

  for(int i = M; i <= Z; i += M) {
    if(A[i]) ans++;
  }

  cout << ans << endl;
}
