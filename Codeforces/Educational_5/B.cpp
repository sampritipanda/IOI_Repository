#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int ans[100];

int main() {
  int N, M; cin >> N >> M;

  int cost = 0;
  for(int i = 0; i < N; i++) {
    ans[i] = INT_MAX;
    for(int j = 0; j < M; j++) {
      int x; cin >> x;
      ans[i] = min(ans[i], x);
    }
    cost = max(cost, ans[i]);
  }

  cout << cost << endl;
}
