#include <iostream>
#include <algorithm>

using namespace std;

struct node {
  int val;
  node *left, *right;

  node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }
};

int A[51][21];
node* tree[51];

void insert(node*& root, int val) {
  if(root == NULL) {
    root = new node(val);
    return;
  }

  if(val < root->val) insert(root->left, val);
  else insert(root->right, val);
}

bool equal(node* left, node* right) {
  if(left == NULL && right != NULL) return false;
  if(left != NULL && right == NULL) return false;
  if(left == NULL && right == NULL) return true;

  return equal(left->left, right->left) && equal(left->right, right->right);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  for(int i = 1; i <= N; i++) {
    tree[i] = NULL;

    for(int j = 1; j <= K; j++) {
      cin >> A[i][j];
      insert(tree[i], A[i][j]);
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    bool dist = true;
    for(int j = 1; j < i; j++) {
      if(equal(tree[i], tree[j])) {
        dist = false;
        break;
      }
    }
    if(dist) ans++;
  }

  cout << ans << endl;
}
