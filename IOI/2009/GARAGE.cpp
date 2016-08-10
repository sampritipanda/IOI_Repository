#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int R[101];
int W[2001];
int pos[2001];
int car[101];

int main() {
  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) cin >> R[i];
  for(int i = 1; i <= M; i++) cin >> W[i];

  for(int i = 1; i <= N; i++) car[i] = -1;
  for(int i = 1; i <= M; i++) pos[i] = -1;

  int ans = 0;
  queue<int> Q;
  for(int t = 0; t < 2 * M; t++) {
    int x; cin >> x;

    if(x > 0) {
      bool added = false;
      for(int i = 1; i <= N; i++) {
        if(car[i] == -1) {
          car[i] = x;
          pos[x] = i;
          ans += W[x] * R[i];
          added = true;
          break;
        }
      }
      if(!added) Q.push(x);
    }
    else {
      int i = pos[-x];
      if(!Q.empty()) {
        int x2 = Q.front(); Q.pop();
        ans += W[x2] * R[i];
        pos[x2] = i;
        car[i] = x2;
        pos[-x] = -1;
      }
      else {
        car[i] = -1;
        pos[-x] = -1;
      }
    }
  }
  cout << ans << endl;
}

