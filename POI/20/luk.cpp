#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[300001];
int K;

int solve(int i, int p) {
  int cnt = 0;

  if(p == 0) cnt = G[i].size();
  else cnt = G[i].size() - 1;

  for(int _ = 0; _ < G[i].size(); _++) {
    int u = G[i][_];
    if(u == p) continue;
    cnt += solve(u, i);
  }

  return (cnt <= K ? 0 : cnt - K);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  int L = 0, R = N;
  while(L < R) {
    int mid = (L + R)/2;
    K = mid;
    if(solve(1, 0) == 0) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }
  cout << L << endl;
}
