#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

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
};

int A[100001];
int A_R[100001];
map<int, int> compres;
node* root[100001];

int query(int L, int R, node* x, node* y, int K) {
  if(L == R) return L;

  int mid = (L + R)/2;
  int cnt = y->left->val - x->left->val;

  if(K <= cnt) {
    return query(L, mid, x->left, y->left, K);
  }
  else {
    return query(mid + 1, R, x->right, y->right, K - cnt);
  }
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  for(int i = 1; i <= N; i++) compres[A[i]];
  int ind = 0; for(auto it: compres) compres[it.first] = ++ind;
  for(int i = 1; i <= N; i++) A_R[compres[A[i]]] = A[i], A[i] = compres[A[i]];

  root[0] = new node(); root[0]->build(1, N);
  for(int i = 1; i <= N; i++) {
    root[i] = root[i - 1]->update(1, N, A[i]);
  }

  while(Q--) {
    int x, y, k; scanf("%d %d %d", &x, &y, &k);

    int ans = query(1, N, root[x - 1], root[y], k);
    printf("%d\n", A_R[ans]);
  }
}
