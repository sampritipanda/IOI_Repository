#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int val;
  node *left, *right;

  node(int _val = 0, node *_left = NULL, node *_right = NULL) {
    val = _val;
    left = _left;
    right = _right;
  }

  void build(int L, int R) {
    if(L == R) {
      return;
    }

    int mid = (L + R)/2;
    left = new node(); left->build(L, mid);
    right = new node(); right->build(mid + 1, R);
  }

  node* update(int L, int R, int pos) {
    if(pos < L || pos > R) return this;

    node* new_node = new node(val + 1);

    if(L != R) {
      int mid = (L + R)/2;
      new_node->left = left->update(L, mid, pos);
      new_node->right = right->update(mid + 1, R, pos);
    }

    return new_node;
  }

  int query(int L, int R, int qL, int qR) {
    if(R < qL || L > qR) return 0;
    if(qL <= L && R <= qR) return val;

    int mid = (L + R)/2;

    return left->query(L, mid, qL, qR) + right->query(mid + 1, R, qL, qR);
  }
};

int N;
vector<int> G[400001];
int S[400001];
int R_S[400001];
int E[400001];
int P[400001];
int sz[400001];
int timer = 0;
int ans[400001];
int top_sz[400001];
node* root[400001];
int bit[400001];

int query(int x) {
  int ans = 0;
  while(x > 0) {
    ans += bit[x];
    x -= x & -x;
  }
  return ans;
}

void update(int x, int v) {
  if(x == 0) return;
  while(x <= 400000) {
    bit[x] += v;
    x += x & -x;
  }
}

void dfs(int i, int p) {
  sz[i] = 1;
  P[i] = p;
  S[i] = ++timer;
  R_S[S[i]] = i;

  for(int u: G[i]) {
    if(u == p) continue;

    dfs(u, i);
    sz[i] += sz[u];
  }

  E[i] = timer;
}

int dfs2(int i, int p, int sum) {
  top_sz[i] = sum;

  for(int u: G[i]) {
    if(u == p) continue;

    dfs2(u, i, sum + sz[i] - sz[u]);
  }
}

int solve(int i, int p) {
  update(sz[i], -1);
  update(top_sz[i], 1);

  int pos = -1;
  for(int u: G[i]) {
    if(u == p) continue;
    if(sz[u] > N/2) {
      pos = u;
      break;
    }
  }
  if(top_sz[i] > N/2) {
    pos = 0;
  }

  if(pos == -1) {
    ans[i] = 1;
  }
  else {
    int req = (pos == 0 ? top_sz[i] : sz[pos]) - N/2;

    if(req <= N/2) {
      if(pos > 0) {
        int cnt = root[E[pos]]->query(1, N, req, N/2) - root[S[pos] - 1]->query(1, N, req, N/2);
        if(cnt > 0) ans[i] = 1;
      }
      else {
        int cnt = query(N/2) - query(req - 1);
        cnt -= root[E[i]]->query(1, N, req, N/2) - root[S[i]]->query(1, N, req, N/2);
        if(cnt > 0) ans[i] = 1;
      }
    }
  }

  for(int u: G[i]) {
    if(u == p) continue;
    solve(u, i);
  }

  update(sz[i], 1);
  update(top_sz[i], -1);
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0);
  dfs2(1, 0, 0);

  root[0] = new node(); root[0]->build(1, N);
  for(int i = 1; i <= N; i++) {
    root[i] = root[i - 1]->update(1, N, sz[R_S[i]]);
  }
  for(int i = 1; i <= N; i++) {
    update(sz[i], 1);
  }

  solve(1, 0);

  for(int i = 1; i <= N; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

