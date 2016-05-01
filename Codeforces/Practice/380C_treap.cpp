#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

char S[1000003];

struct info {
  int X, Y, ans;

  info() {
    X = Y = ans = 0;
  }

  info(char c) {
    X = Y = ans = 0;
    if(c == '(') X++;
    else if(c == ')') Y++;
  }
};

info merge(info L, info R) {
  info N;

  int am_add = min(L.X, R.Y);
  N.ans = L.ans + R.ans + 2 * am_add;
  N.X = L.X - am_add + R.X;
  N.Y = L.Y + R.Y - am_add;

  return N;
}

struct node {
  int p; char val;
  int cnt; info I;
  node *left, *right;

  node(int, int, node*, node*);
  void upd();
};

inline int cnt(node* N) {
  if(N == NULL) return 0;
  else return N->cnt;
}

inline info get_info(node* N) {
  if(N == NULL) return info();
  else return N->I;
}

void node::upd() {
  cnt = 1;
  if(left != NULL) cnt += left->cnt;
  if(right != NULL) cnt += right->cnt;

  if(left == NULL && right == NULL) I = info(val);
  else I = merge(merge(get_info(left), info(val)), get_info(right));
}

node::node(int _p, int _val, node *_left = NULL, node *_right = NULL) {
  p = _p;
  val = _val;
  left = _left;
  right = _right;

  upd();
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

void insert(node*& root, int X, int p, char val, int pre) {
  if(root == NULL) {
    root = new node(p, val);
    return;
  }

  int key = pre + cnt(root->left) + 1;
  if(X < key) {
    insert(root->left, X, p, val, pre);
    if(root->left->p < root->p) rotate_right(root);
  }
  else {
    insert(root->right, X, p, val, pre + cnt(root->left) + 1);
    if(root->right->p < root->p) rotate_left(root);
  }

  root->upd();
}

void split(node*& root, int X, int p = -1) {
  insert(root, X, p, '-', 0);
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
    merge(L->right, L->right, R);
    root = L;
  }
  else {
    merge(R->left, L, R->left);
    root = R;
  }

  root->upd();
}

void delete_node(node*& root, int X, int pre) {
  if(root == NULL) return;

  int key = pre + cnt(root->left) + 1;
  if(X < key) {
    delete_node(root->left, X, pre);
  }
  else if(X > key) {
    delete_node(root->right, X, pre + cnt(root->left) + 1);
  }
  else {
    merge(root, root->left, root->right);
  }

  if(root != NULL) root->upd();
}

int main() {
  srand(time(NULL));

  scanf("%s", S);
  int N = strlen(S);

  node* root = new node(rand(), S[0]);
  for(int i = 2; i <= N; i++) {
    merge(root, root, new node(rand(), S[i - 1]));
  }

  int M; scanf("%d", &M);

  while(M--) {
    int L, R; scanf("%d %d", &L, &R);

    split(root, R, -2);
    split(root->left, L - 1);

    printf("%d\n", root->left->right->I.ans);

    merge(root->left, root->left->left, root->left->right);
    merge(root, root->left, root->right);
  }
}
