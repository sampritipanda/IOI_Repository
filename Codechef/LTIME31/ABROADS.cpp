#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct query {
  // type: 1 = delete, 2 = change pop
  int type, K, A, x;
};

vector<pair<int, int> > edges;
vector<bool> valid_edge;
vector<vector<int> > A;
vector<int> U; vector<long long> sz;
vector<query> queries;
multiset<long long> sizes;
vector<long long> ans;

int find(int i) {
  if(U[i] == i) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  U[a] = b;
  if(a == b) return;

  sizes.erase(sizes.find(sz[a]));
  sizes.erase(sizes.find(sz[b]));
  sz[b] += sz[a];
  sz[a] = 0;
  sizes.insert(sz[a]);
  sizes.insert(sz[b]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;

  A.resize(N + 1);
  edges.resize(M + 1);
  valid_edge.resize(M + 1);

  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    A[i].push_back(x);
  }

  for(int i = 1; i <= M; i++) {
    int x, y; cin >> x >> y;
    edges[i] = {x, y};
    valid_edge[i] = true;
  }

  for(int i = 0; i < Q; i++) {
    char type; cin >> type;
    query curr;

    if(type == 'D') {
      curr.type = 1;
      cin >> curr.K;
      valid_edge[curr.K] = false;
    }
    else {
      curr.type = 2;
      cin >> curr.A >> curr.x;
      A[curr.A].push_back(curr.x);
    }

    queries.push_back(curr);
  }

  U.resize(N + 1);
  sz.resize(N + 1);

  for(int i = 1; i <= N; i++) {
    U[i] = i;
    sz[i] = A[i].back();
    sizes.insert(sz[i]);
  }

  for(int i = 1; i <= M; i++) {
    if(valid_edge[i]) merge(edges[i].first, edges[i].second);
  }

  for(int i = Q - 1; i >= 0; i--) {
    ans.push_back(*sizes.rbegin());

    if(queries[i].type == 1) {
      int x = edges[queries[i].K].first, y = edges[queries[i].K].second;
      merge(x, y);
      valid_edge[queries[i].K] = true;
    }
    else {
      int j = queries[i].A, x = queries[i].x;
      A[j].pop_back();
      int k = find(j);
      sizes.erase(sizes.find(sz[k]));
      sz[k] = sz[k] - x + A[j].back();
      sizes.insert(sz[k]);
    }
  }

  reverse(ans.begin(), ans.end());
  for(auto it: ans) cout << it << endl;
}
