#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  int colors[K + 1];
  for(int i = 0; i <= K; i++) colors[i] = 0;
  int each = N/K;

  for(int i = 0; i < N; i++) {
    int c; cin >> c;
    colors[c]++;
  }

  int ans = 0;
  for(int i = 1; i <= K; i++) {
    if(colors[i] < each) ans += each - colors[i];
  }
  cout << ans << endl;
}
