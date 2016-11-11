#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, B, D; cin >> N >> B >> D;

  int W = 0;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x > B) continue;

    W += x;
    if(W > D) {
      W = 0;
      ans++;
    }
  }

  cout << ans << endl;
}

