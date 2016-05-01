#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> G[100001];
int P[100001];
int D[100001];
int col[100001];
set<int> ans;
int K;

inline int lca(int A, int B) {
  if(A > B) swap(A, B);
  B >>= D[B] - D[A];
  while(A != B) {
    A /= 2;
    B /= 2;
  }
  return A;
}

void dfs(int i, int p) {
  ans.insert(col[i]);

  for(int u: G[i]) {
    if(u != p) dfs(u, i);
  }
}

void upd_dfs(int i, int p, int c) {
  col[i] = c;
  if(c == K) return;

  for(int u: G[i]) {
    if(u != p) upd_dfs(u, i, c + 1);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, Q; cin >> N >> Q;

  for(int i = 1; i <= N; i++) {
    P[i] = i/2;
    D[i] = D[i/2] + 1;
  }

  for(int i = 2; i <= N; i++) {
    G[i].push_back(P[i]);
    G[P[i]].push_back(i);
  }

  while(Q--) {
    int t; cin >> t;

    if(t == 1) {
      int X; cin >> X >> K;
      upd_dfs(X, 0, 0);
    }
    else if(t == 2) {
      int X, Y; cin >> X >> Y;
      int L = lca(X, Y);
      ans.clear();
      while(X != L) {
        ans.insert(col[X]); X /= 2;
      }
      while(Y != L) {
        ans.insert(col[Y]); Y /= 2;
      }
      ans.insert(col[L]);
      ans.erase(0);
      cout << ans.size() << endl;
    }
    else {
      int X; cin >> X;
      ans.clear();
      dfs(X, P[X]);
      ans.erase(0);
      cout << ans.size() << endl;
    }
  }
}
