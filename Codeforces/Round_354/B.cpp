#include <iostream>
#include <algorithm>

using namespace std;

int N;
long double A[11][11];

void add(int i, int j, long double am) {
  A[i][j] += am;
  long double left = 0.0;
  if(A[i][j] > 1.0) {
    left = A[i][j] - 1.0;
    A[i][j] = 1.0;
  }

  if(i < N && left > 0) {
    add(i + 1, j, left/2);
    add(i + 1, j + 1, left/2);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> N >> T;

  while(T--) {
    add(1, 1, 1);
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) {
      if(A[i][j] >= 1.0) ans++;
    }
  }
  cout << ans << endl;
}
