#include <cstdio>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

unordered_map<int, int> U[100001];
set<int> G[100001];
pair<int, int > queries[100001];
set<int> Q_G[100001];
map<pair<int, int>, int > query_map;

int find(int c, int i) {
  if(U[c].count(i) == 0) return -1;
  if(U[c][i] == i) return i;
  return U[c][i] = find(c, U[c][i]);
}

void merge(int c, int a, int b) {
  if(U[c].count(a) == 0) U[c][a] = a;
  if(U[c].count(b) == 0) U[c][b] = b;

  a = find(c, a);
  b = find(c, b);

  U[c][a] = b;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  while(M--) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    G[a].insert(c);
    G[b].insert(c);

    merge(c, a, b);
  }

  int Q; scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    scanf("%d %d", &queries[i].first, &queries[i].second);
    if(G[queries[i].first].size() < G[queries[i].second].size()) {
      Q_G[queries[i].first].insert(queries[i].second);
    }
    else {
      Q_G[queries[i].second].insert(queries[i].first);
    }
  }

  /*
     for each node,
       for each color from this node
         for each query from this node to other
           if both nodes in same color comp
             query_ans++
  */

  for(int i = 1; i <= N; i++) {
    for(int c: G[i]) {
      for(int v: Q_G[i]) {
        if(find(c, i) == find(c, v)) {
          query_map[{i, v}]++;
        }
      }
    }
  }

  for(int i = 0; i < Q; i++) {
    int u = queries[i].first, v = queries[i].second;
    printf("%d\n", max(query_map[{u, v}], query_map[{v, u}]));
  }
}
