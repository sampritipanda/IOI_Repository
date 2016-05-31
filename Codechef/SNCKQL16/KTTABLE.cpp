#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[10001];
int B[10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    A[0] = 0;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];

    int ans = 0;
    for(int i = 1; i <= N; i++) {
      if(B[i] <= A[i] - A[i - 1]) ans++;
    }
    cout << ans << endl;
  }
}
