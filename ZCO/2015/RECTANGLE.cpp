// Rectangle

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000, M = 500;

int P[N + 1];

int main() {
  for(int i = 0; i <= N; i++) P[i] = M;

  int Q; cin >> Q;

  while(Q--) {
    int x, y; cin >> x >> y;
    P[x] = min(P[x], y);
  }

  int ans = 0;
  for(int h = 1; h <= M; h++) {
    int best = 0, curr = 0;
    for(int i = 1; i <= N - 1; i++) {
      if(P[i] >= h) curr++;
      else curr = 0;

      best = max(best, curr);
    }

    ans = max(ans, (best + 1) * h);
  }
  cout << ans << endl;
}
