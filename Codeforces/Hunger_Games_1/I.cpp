// Hamro and Khikland's map

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int union_find[1001];
vector<pair<int, pair<int, int> > > edges;

int find(int a) {
  if(a == union_find[a]) return a;
  else return union_find[a] = find(union_find[a]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  union_find[a] = b;
}

int main() {
  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) union_find[i] = i;

  long long total_cost = 0;

  for(int i = 0; i < M; i++) {
    int a, b, w; cin >> a >> b >> w;
    edges.push_back({w, {a, b}});
    edges.push_back({w, {b, a}});
    merge(a, b);

    total_cost += w;
  }

  bool possible = true;
  for(int i = 2; i <= N; i++) {
    if(find(i) != find(1)) {
      possible = false;
      break;
    }
  }

  if(possible) {
    for(int i = 1; i <= N; i++) union_find[i] = i;
    sort(edges.begin(), edges.end());

    long long mst = 0;
    for(auto it: edges) {
      int w = it.first, a = it.second.first, b = it.second.second;
      if(find(a) == find(b)) continue;
      mst += w;
      merge(a, b);
    }

    cout << total_cost - mst << endl;
  }
  else {
    cout << -1 << endl;
  }
}
