#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct edge {
  int d;
  int x, y;
};

int U[2005];
vector<edge> edges;

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

bool compare(edge A, edge B) {
  return A.d < B.d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      int x; cin >> x;
      if(i == 1 || j == 1) continue;
      edge E; E.d = x; E.x = i; E.y = j;
      edges.push_back(E);
    }
  }

  sort(edges.begin(), edges.end(), compare);
  int M = edges.size();

  for(int i = 1; i <= N; i++) U[i] = i;

  long long ans = 0;
  for(int i = 0; i < M; i++) {
    long long d = edges[i].d; int x = edges[i].x, y = edges[i].y;
    if(find(x) != find(y)) {
      ans += d;
      merge(x, y);
    }
  }

  cout << ans << endl;
}
