#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int power[101];
vector<pair<int, pair<int, int>> > edges;
int U[101];
int N;

int find(int i) {
  if(i == U[i]) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    U[a] = b;
  }
}

bool connected(int u) {
  for(int i = 1; i <= N; i++) {
    if(power[i] && find(i) == find(u)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int K; cin >> N >> K;

  for(int i = 0; i <= 100; i++) U[i] = i;

  while(K--) {
    int x; cin >> x;
    power[x] = true;
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      int x; cin >> x;
      if(i == j) continue;

      edges.push_back({x, {i, j}});
    }
  }

  sort(edges.begin(), edges.end());

  int ans = 0;
  for(auto it: edges) {
    int x = it.first, i = it.second.first, j = it.second.second;

    if(power[i] && power[j]) continue;
    if(connected(i) && connected(j)) continue;
    if(find(i) == find(j)) continue;

    ans += x;
    merge(i, j);
  }

  cout << ans << endl;
}
