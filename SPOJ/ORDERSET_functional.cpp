#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct node {
  int p, key, cnt;
  node *left, *right;

  node(int _p, int _key, node* _left = NULL, node* _right = NULL) {
    p = _p;
    key = _key;
    left = _left;
    right = _right;

    cnt = 1;
    if(left != NULL) cnt += left->cnt;
    if(right != NULL) cnt += right->cnt;
  }
};

inline int cnt(node* root) {
  return (root == NULL ? 0 : root->cnt);
}

node* rotate_right(node* root) {
  node* new_right = new node(root->p, root->key, root->left->right, root->right);
  return new node(root->left->p, root->left->key, root->left->left, new_right);
}

node* rotate_left(node* root) {
  node* new_left = new node(root->p, root->key, root->left, root->right->left);
  return new node(root->right->p, root->right->key, new_left, root->right->right);
}

node* insert(node* root, int X, int p) {
  if(root == NULL) {
    return new node(p, X);
  }

  if(X < root->key) {
    node* new_node = new node(root->p, root->key, insert(root->left, X, p), root->right);
    if(new_node->left->p < new_node->p) return rotate_right(new_node);
    return new_node;
  }
  else if(X > root->key){
    node* new_node = new node(root->p, root->key, root->left, insert(root->right, X, p));
    if(new_node->right->p < new_node->p) return rotate_left(new_node);
    return new_node;
  }
  else {
    return root;
  }
}

node* merge(node* L, node* R) {
  if(L == NULL) return R;
  if(R == NULL) return L;

  if(L->p <= R->p) {
    return new node(L->p, L->key, L->left, merge(L->right, R));
  }
  else {
    return new node(R->p, R->key, merge(L, R->left), R->right);
  }
}

node* split(node* root, int X) {
  return insert(root, X, -1);
}

node* delete_node(node* root, int X) {
  if(root == NULL) {
    return NULL;
  }

  if(X < root->key) {
    return new node(root->p, root->key, delete_node(root->left, X), root->right);
  }
  else if(X > root->key) {
    return new node(root->p, root->key, root->left, delete_node(root->right, X));
  }
  else {
    return merge(root->left, root->right);
  }
}

node* kth_min(node* root, int K) {
  if(root == NULL) return NULL;

  if(K <= cnt(root->left)) {
    return kth_min(root->left, K);
  }
  else if(K == cnt(root->left) + 1){
    return root;
  }
  else {
    return kth_min(root->right, K - cnt(root->left) - 1);
  }
}

int count_less(node* root, int X) {
  if(root == NULL) return 0;

  if(X > root->key) {
    return cnt(root->left) + 1 + count_less(root->right, X);
  }
  else {
    return count_less(root->left, X);
  }
}

int main() {
  srand(time(NULL));

  node* root = NULL;

  int Q; scanf("%d", &Q);
  while(Q--) {
    char t; int x; scanf(" %c %d", &t, &x);

    if(t == 'I') {
      int p = rand();
      root = insert(root, x, p);
    }
    else if(t == 'D') {
      root = delete_node(root, x);
    }
    else if(t == 'K') {
      node* req = kth_min(root, x);

      if(req == NULL) printf("invalid\n");
      else printf("%d\n", req->key);
    }
    else {
      printf("%d\n", count_less(root, x));
    }
  }
}

