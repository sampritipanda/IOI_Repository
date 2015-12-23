#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  vector<int> A(M + 1, 0);
  while(N--) {
    int x; cin >> x;
    A[x]++;
  }

  long long ans = 0;
  for(int i = 1; i <= M; i++) {
    for(int j = i + 1; j <= M; j++) {
      ans += A[i] * A[j];
    }
  }
  cout << ans << endl;
}
