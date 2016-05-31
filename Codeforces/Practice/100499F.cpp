#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

struct node {
  node *left, *right, *parent;
  int u, p, type;
  int sum, cnt;

  node(int _u, int _p, int _type) {
    u = _u;
    p = _p;
    type = _type;
    left = NULL;
    right = NULL;

    upd();
  }

  void upd() {
    sum = type;
    cnt = 1;
    parent = NULL;

    if(left != NULL) {
      sum += left->sum;
      cnt += left->cnt;
      left->parent = this;
    }
    if(right != NULL) {
      sum += right->sum;
      cnt += right->cnt;
      right->parent = this;
    }
  }
};

int get_cnt(node* N) {
  if(N == NULL) return 0;
  return N->cnt;
}

int get_sum(node* N) {
  if(N == NULL) return 0;
  return N->sum;
}

void del_treap(node*& root) {
  if(root == NULL) return;

  del_treap(root->left);
  del_treap(root->right);

  delete root;
  root = NULL;
}

void rotate_right(node*& root) {
  node* temp = root;
  root = root->left;
  temp->left = root->right;
  root->right = temp;

  temp->upd();
}

void rotate_left(node*& root) {
  node* temp = root;
  root = root->right;
  temp->right = root->left;
  root->left = temp;

  temp->upd();
}

void insert(node*& root, int X, int u, int p, int type, int pre = 0) {
  if(root == NULL) {
    root = new node(u, p, type);
    return;
  }

  int key = pre + get_cnt(root->left) + 1;

  if(X < key) {
    insert(root->left, X, u, p, type, pre);
    if(root->left->p < root->p) rotate_right(root);
  }
  else {
    insert(root->right, X, u, p, type, key);
    if(root->right->p < root->p) rotate_left(root);
  }

  root->upd();
}

void merge(node*& root, node* L, node* R) {
  if(L == NULL) {
    root = R;
    return;
  }
  if(R == NULL) {
    root = L;
    return;
  }

  if(L->p <= R->p) {
    root = L;
    merge(root->right, L->right, R);
  }
  else {
    root = R;
    merge(root->left, L, R->left);
  }

  root->upd();
}

void split(node*& root, int X, int p = -1) {
  insert(root, X, 0, p, 0);
}

// #include <iostream>
// void _print_treap(node* root) {
//   if(root == NULL) return;
//
//   _print_treap(root->left);
//   cout << root->u << " ";
//   _print_treap(root->right);
// }
// void print_treap(node* root) {
//   _print_treap(root);
//   cout << endl;
// }

vector<int> G[100001];
int timer = 0;
int S[100001], E[100001];
node* N_M[200001];

void dfs(int i, node*& root) {
  S[i] = ++timer;
  N_M[S[i]] = new node(i, rand(), 1);
  merge(root, root, N_M[S[i]]);

  for(int u: G[i]) {
    dfs(u, root);
  }

  E[i] = ++timer;
  N_M[E[i]] = new node(i, rand(), 0);
  merge(root, root, N_M[E[i]]);
}

int findX(node* N) {
  int ans = get_cnt(N->left) + 1;
  while(true) {
    if(N->parent == NULL) break;
    if(N == N->parent->right) ans += get_cnt(N->parent->left) + 1;
    N = N->parent;
  }
  return ans;
}

int kth_query(node*& root, int k) {
  int sum = get_sum(root->left) + root->type;

  if(k == sum && root->type) {
    return root->u;
  }
  else if(k <= sum) {
    return kth_query(root->left, k);
  }
  else {
    return kth_query(root->right, k - sum);
  }
}

int main() {
  srand(0);

  int T; scanf("%d", &T);

  node* root = NULL;

  while(T--) {
    int N; scanf("%d", &N);

    del_treap(root);
    for(int i = 1; i <= N; i++) {
      G[i].clear();
      S[i] = E[i] = 0;
    }
    for(int i = 1; i <= 2*N; i++) {
      N_M[i] = NULL;
    }

    for(int i = 0; i < N - 1; i++) {
      int u, v; scanf("%d %d", &u, &v);
      G[u].push_back(v);
    }

    timer = 0;
    dfs(1, root);

    int Q; scanf("%d", &Q);

    while(Q--) {
      int t; scanf("%d", &t);

      if(t == 1) {
        int u, v; scanf("%d %d'", &u, &v);
        int L = findX(N_M[S[u]]), R = findX(N_M[E[u]]);
        split(root, R, -2); split(root->left, L - 1);
        node* subarray = root->left->right;
        merge(root, root->left->left, root->right);

        split(root, findX(N_M[E[v]]) - 1);
        merge(root->left, root->left, subarray);
        merge(root, root->left, root->right);
      }
      else {
        int k; scanf("%d", &k);

        printf("%d\n", kth_query(root, k));
      }
    }
  }
}
