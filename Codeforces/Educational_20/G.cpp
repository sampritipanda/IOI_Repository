#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N, K;
int B[100001];
int ST[18][100001];

int sparse_query(int L, int R) {
  int t = log(R - L + 1)/log(2);
  int p = 1 << t;
  return min(ST[t][L], ST[t][R - p + 1]);
}

int direct_query(int L, int R) {
  if(R - L + 1 >= N) return sparse_query(1, N);
  if((L - 1)/N == (R - 1)/N) return sparse_query((L - 1) % N + 1, (R - 1) % N + 1);
  return min(sparse_query((L - 1) % N + 1, N), sparse_query(1, (R - 1) % N + 1));
}

class node {
public:
  int min, lazy;
  node *left, *right;

  node(int L, int R) {
    min = direct_query(L, R);
    lazy = INT_MAX/2;
    left = right = NULL;
  }
};

void propagate(node*& root, int L, int R) {
  if(root == NULL) root = new node(L, R);
  if(root->lazy == INT_MAX/2) return;

  root->min = root->lazy;

  if(L != R) {
    int mid = (L + R)/2;
    if(root->left == NULL) root->left = new node(L, mid);
    if(root->right == NULL) root->right = new node(mid + 1, R);
    root->left->lazy = root->lazy;
    root->right->lazy = root->lazy;
  }

  root->lazy = INT_MAX/2;
}

void update(node*& root, int L, int R, int qL, int qR, int val) {
  if(root == NULL) root = new node(L, R);
  propagate(root, L, R);
  if(L > qR || R < qL) return;
  if(qL <= L && R <= qR) {
    root->lazy = val;
    propagate(root, L, R);
    return;
  }

  int mid = (L + R)/2;
  update(root->left, L, mid, qL, qR, val);
  update(root->right, mid + 1, R, qL, qR, val);
  root->min = min(root->left->min, root->right->min);
}

int query(node*& root, int L, int R, int qL, int qR) {
  if(L > qR || R < qL) return INT_MAX/2;
  if(root == NULL) {
    if(L <= qL && qR <= R) return direct_query(qL, qR);
    if(qL <= L && R <= qR) return direct_query(L, R);
    if(qL <= L && qR <= R) return direct_query(L, qR);
    if(L <= qL && R <= qR) return direct_query(qL, R);
  }
  propagate(root, L, R);
  if(qL <= L && R <= qR) return root->min;

  int mid = (L + R)/2;
  return min(query(root->left, L, mid, qL, qR), query(root->right, mid + 1, R, qL, qR));
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

  for(int i = 1; i <= N; i++) ST[0][i] = B[i];
  for(int j = 1; (1 << j) <= N; j++) {
    for(int i = 1; i <= N; i++) {
      ST[j][i] = INT_MAX/2;
      if(i + (1 << j) - 1 <= N) ST[j][i] = min(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
    }
  }

  int Q; scanf("%d", &Q);

  node *root = new node(1, N * K);

  while(Q--) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int L, R, x; scanf("%d %d %d", &L, &R, &x);
      update(root, 1, N * K, L, R, x);
    }
    else {
      int L, R; scanf("%d %d", &L, &R);
      printf("%d\n", query(root, 1, N * K, L, R));
    }
  }
}
