#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[300005];

int U[300005];
int D[300005];
bool vis[300005];

int find(int i) {
  if(i == U[i]) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b, bool flag) {
  if(rand() < 0.5) swap(a, b);

  a = find(a), b = find(b);
  if(a != b) {
    U[b] = a;

    if(flag) {
      D[a] = max(max(D[a], D[b]), (D[a] + 1)/2 + 1 + (D[b] + 1)/2);
      D[b] = 0;
    }
  }
}

int main() {
  int N, M, Q; scanf("%d %d %d", &N, &M, &Q);

  for(int i = 1; i <= N; i++) U[i] = i;

  while(M--) {
    int a, b; scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);

    merge(a, b, 0);
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    queue<vector<int> > Q;  // {vertex,  parent}
    Q.push({i, -1});

    int last_node = -1;
    while(!Q.empty()) {
      int i = Q.front()[0], p = Q.front()[1];
      Q.pop();

      last_node = i;

      for(auto v: G[i]) {
        if(v == p) continue;

        Q.push({v, i});
      }
    }

    int diameter = 0;
    Q.push({last_node, 0}); // {vertex, dist}

    while(!Q.empty()) {
      int i = Q.front()[0], d = Q.front()[1];
      Q.pop();

      if(vis[i]) continue;
      vis[i] = true;

      diameter = max(diameter, d);

      for(auto v: G[i]) {
        Q.push({v, d + 1});
      }
    }

    D[find(i)] = diameter;
  }

  while(Q--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int x; scanf("%d", &x);

      printf("%d\n", D[find(x)]);
    }
    else {
      int x, y; scanf("%d %d", &x, &y);
      merge(x, y, 1);
    }
  }
}
