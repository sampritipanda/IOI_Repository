#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <ctime>

using namespace std;

struct info {
  int l_sum, r_sum, sum, ans;

  info() {
    l_sum = r_sum = ans = INT_MIN/2;
    sum = 0;
  }

  info(int x) {
    l_sum = r_sum = sum = ans = x;
  }
};

struct node {
  int p, cnt, val;
  node *left, *right;
  info I;

  void upd();
  node(int, int, node*, node*);
};

// merges info nodes of L and R
info merge(info L, info R) {
  info N;

  N.l_sum = max(L.l_sum, L.sum + R.l_sum);
  N.r_sum = max(R.r_sum, R.sum + L.r_sum);
  N.sum = L.sum + R.sum;
  N.ans = max(L.r_sum + R.l_sum, max(L.ans, R.ans));

  return N;
}

inline int cnt(node* root) {
  if(root == NULL) return 0;
  return root->cnt;
}

inline info get_info(node* root) {
  if(root == NULL) return info();
  return root->I;
}

inline void node::upd() {
  if(left == NULL && right == NULL) I = info(val);
  else I = merge(merge(get_info(left), info(val)), get_info(right));

  cnt = 1;
  if(left != NULL) cnt += left->cnt;
  if(right != NULL) cnt += right->cnt;
}

node::node(int _p, int _val, node* _left = NULL, node* _right = NULL) {
  p = _p;
  val = _val;
  left = _left;
  right = _right;

  upd();
}

inline void rotate_right(node*& root) {
  node* temp = root;
  root = root->left;
  temp->left = root->right;
  root->right = temp;

  temp->upd();
}

inline void rotate_left(node*& root) {
  node* temp = root;
  root = root->right;
  temp->right = root->left;
  root->left = temp;

  temp->upd();
}

void insert(node*& root, int X, int val, int p, int pre) {
  if(root == NULL) {
    root = new node(p, val);
    return;
  }

  int key = pre + cnt(root->left) + 1;
  if(X < key) {
    insert(root->left, X, val, p, pre);
    if(root->left->p < root->p) rotate_right(root);
  }
  else {
    insert(root->right, X, val, p, pre + cnt(root->left) + 1);
    if(root->right->p < root->p) rotate_left(root);
  }

  root->upd();
}

// Splits treap into [0..X] and [(X+1)..end]
inline void split(node*& root, int X, int p = -1) {
  insert(root, X, 0, p, 0);
}

void merge_treap(node*&root, node* L, node* R) {
  if(L == NULL) {
    root = R;
    return;
  }
  if(R == NULL) {
    root = L;
    return;
  }

  if(L->p <= R->p) {
    merge_treap(L->right, L->right, R);
    root = L;
  }
  else {
    merge_treap(R->left, L, R->left);
    root = R;
  }

  root->upd();
}

void delete_node(node*& root, int X, int pre) {
  if(root == NULL) return;

  int key = pre + cnt(root->left) + 1;
  if(X < key) {
    delete_node(root->left, X, pre);
    root->upd();
  }
  else if(X > key) {
    delete_node(root->right, X, pre + cnt(root->left) + 1);
    root->upd();
  }
  else {
    merge_treap(root, root->left, root->right);
  }
}

inline info query(node*& root, int L, int R) {
  split(root, R, -2);
  split(root->left, L - 1);

  info ans = root->left->right->I;

  merge_treap(root->left, root->left->left, root->left->right);
  merge_treap(root, root->left, root->right);

  return ans;
}

int main() {
  int N; scanf("%d", &N);

  srand(time(NULL));

  int x; scanf("%d", &x);
  node* root = new node(rand(), x);

  for(int i = 2; i <= N; i++) {
    scanf("%d", &x);
    merge_treap(root, root, new node(rand(), x));
  }

  int Q; scanf("%d", &Q);

  while(Q--) {
    char t; scanf(" %c", &t);

    // insert
    if(t == 'I') {
      int i, x; scanf("%d %d", &i, &x);
      insert(root, i - 1, x, rand(), 0);
    }
    // update
    else if(t == 'R') {
      int i, x; scanf("%d %d", &i, &x);
      split(root, i);
      delete_node(root->left, i, 0);  // left contains previous element.
      insert(root->left, i - 1, x, rand(), 0);
      merge_treap(root, root->left, root->right);
    }
    // delete
    else if(t == 'D') {
      int i; scanf("%d", &i);
      delete_node(root, i, 0);
    }
    // query
    else {
      int L, R; scanf("%d %d", &L, &R);
      printf("%d\n", query(root, L, R).ans);
    }
  }
}
