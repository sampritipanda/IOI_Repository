#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int A[300001];
vector<int> G[300001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int ans = INT_MAX;

  multiset<int> S;
  for(int i = 1; i <= N; i++) S.insert(A[i]);

  for(int i = 1; i <= N; i++) {
    int curr_max = INT_MIN;
    curr_max = max(curr_max, A[i]);
    S.erase(S.find(A[i]));
    for(int u: G[i]) {
      curr_max = max(curr_max, A[u] + 1);
      S.erase(S.find(A[u]));
    }
    if(S.size() > 0) {
      curr_max = max(curr_max, *S.rbegin() + 2);
    }
    for(int u: G[i]) {
      S.insert(A[u]);
    }
    S.insert(A[i]);
    ans = min(ans, curr_max);
  }

  cout << ans << endl;
}
