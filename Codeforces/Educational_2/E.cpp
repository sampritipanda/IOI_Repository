#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<vector<int> > G;
int A[100001];
long long ans[100001];
int U[100001];
int cnt[100001];
long long sum[100001];
map<int, int> M[100001];

void merge(int a, int b) {
}

void dfs(int i, int parent) {
  for(auto v: G[i]) {
    if(v == parent) continue;
    dfs(v, i);

    if(M[U[i]].size() < M[U[v]].size()) swap(U[i], U[v]);

    for(auto it: M[U[v]]) {
      M[U[i]][it.first] += it.second;

      if(cnt[U[i]] < M[U[i]][it.first]) {
        cnt[U[i]] = M[U[i]][it.first];
        sum[U[i]] = it.first;
      }
      else if(cnt[U[i]] == M[U[i]][it.first]) {
        sum[U[i]] += it.first;
      }
    }
  }

  ans[i] = sum[U[i]];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  G.resize(N + 1);

  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) {
    U[i] = i;
    M[i][A[i]] = 1;
    sum[i] = A[i];
    cnt[i] = 1;
  }

  for(int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(1, 0);

  for(int i = 1; i <= N; i++) cout << ans[i] << " ";
  cout << endl;
}
