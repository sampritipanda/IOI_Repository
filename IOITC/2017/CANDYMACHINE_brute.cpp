#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

pair<int, int> A[100000];
int vis[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int s, t; cin >> s >> t;
    A[i] = {s + t, t - s};
  }
  sort(A, A + N);

  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;
    ans++;
    vector<int> curr = {i};
    for(int j = i + 1; j < N; j++) {
      if(vis[j]) continue;
      if(A[curr.back()].second <= A[j].second) curr.push_back(j);
    }
    for(int x: curr) vis[x] = true;
  }
  cout << ans << endl;
}
