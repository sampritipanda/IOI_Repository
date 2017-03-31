#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int A[1001];
int vis[2000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 0; i < K; i++) {
    int x; cin >> x;
    A[x] = 1;
  }

  int ans = -1;
  queue<pair<int, int> > Q;  // {val, dist}
  for(int i = 0; i <= 1000; i++) {
    if(A[i]) Q.push({i - N, 1});
  }

  int min_R = -1, max_L = -1;
  for(int i = N; i <= 1000; i++) {
    if(A[i]) {
      min_R = i;
      break;
    }
  }
  for(int i = N; i >= 0; i--) {
    if(A[i]) {
      max_L = i;
      break;
    }
  }
  int max_ans;
  if(max_L == -1 || min_R == -1) max_ans = -1;
  else max_ans = min_R - max_L;

  while(!Q.empty()) {
    auto it = Q.front(); Q.pop();
    int x = it.first, d = it.second;
    if(vis[x + 1000000]) continue;
    vis[x + 1000000] = true;
    if(x == 0) {
      ans = d;
      break;
    }
    if(d > max_ans) continue;

    for(int i = 0; i <= 1000; i++) {
      if(A[i] && x + (i - N) >= -1000000 && x + (i - N) <= 1000000) Q.push({x + (i - N), d + 1});
    }
  }

  cout << ans << endl;
}
