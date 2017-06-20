#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

struct node {
  int p, cnt;
  int val, sum;
  node *left, *right;

  node(int, int, node*, node*);
  void upd();
};

inline int get_cnt(node *N) {
  if(N == NULL) return 0;
  return N->cnt;
}

inline int get_sum(node *N) {
  if(N == NULL) return 0;
  return N->sum;
}

node::node(int _val, int _p, node *_left = NULL, node *_right = NULL) {
  val = _val;
  p = _p;
  left = _left;
  right = _right;

  upd();
}

void node::upd() {
  cnt = 1;
  cnt += get_cnt(left);
  cnt += get_cnt(right);
  sum = get_sum(left) + val + get_sum(right);
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

void insert(node*& root, int X, int val, int p, int pre = 0) {
  if(root == NULL) {
    root = new node(val, p);
    return;
  }

  int key = pre + get_cnt(root->left);

  if(X <= key) {
    insert(root->left, X, val, p, pre);
    if(root->left->p < root->p) rotate_right(root);
  }
  else {
    insert(root->right, X, val, p, key + 1);
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
    merge(root->right, root->right, R);
  }
  else {
    root = R;
    merge(root->left, L, root->left);
  }

  root->upd();
}

node* find_node(node* root, int X, int pre = 0) {
  if(root == NULL) return NULL;

  int key = pre + get_cnt(root->left);

  if(X < key) {
    return find_node(root->left, X, pre);
  }
  else if(X > key) {
    return find_node(root->right, X, key + 1);
  }
  else {
    return root;
  }
}

void delete_node(node*& root, int X, int pre = 0) {
  if(root == NULL) return;

  int key = pre + get_cnt(root->left);

  if(X < key) {
    delete_node(root->left, X, pre);
  }
  else if(X > key) {
    delete_node(root->right, X, key + 1);
  }
  else {
    merge(root, root->left, root->right);
  }

  if(root != NULL) {
    root->upd();
  }
}

void split(node*& root, int X, int p = -1) {
  insert(root, X, INT_MIN/2, p);
}

pair<int, int> search(node* root, int sum, int pre = 0) {
  if(root == NULL) return {pre, sum};

  if(get_sum(root->left) + root->val < sum) {
    return search(root->right, sum - (get_sum(root->left) + root->val), pre + get_cnt(root->left) + 1);
  }
  else {
    return search(root->left, sum, pre);
  }
}

void _print_treap(node* root) {
  if(root == NULL) return;

  _print_treap(root->left);
  cout << root->val << " ";
  _print_treap(root->right);
}
void print_treap(node* root) {
  _print_treap(root);
  cout << endl;
}

#define MAX_N 100000
#define MAX_H 100000

int H[MAX_N + 1], K[MAX_N + 1];
vector<int> by_height[MAX_H + 1];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  srand(time(NULL));

  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> H[i] >> K[i];
    by_height[H[i]].push_back(i);
  }

  node* root = new node(0, rand());
  for(int i = 1; i <= MAX_H + 1; i++) {
    insert(root, i, 0, rand());
  }

  for(int h = 1; h <= MAX_H; h++) {
    int freq_0 = find_node(root, 0)->val + 1;
    delete_node(root, 0);
    insert(root, 0, freq_0, rand());
    for(int i: by_height[h]) {
      if(K[i] <= freq_0) {
        int freq_1 = find_node(root, 1)->val;
        delete_node(root, 1);
        delete_node(root, 0);
        freq_0 -= K[i];
        freq_1 += K[i];
        insert(root, 0, freq_0, rand());
        insert(root, 1, freq_1, rand());
      }
      else {
        pair<int, int> tmp = search(root, K[i]);
        int ind = tmp.first, remain = tmp.second;
        int prev_val = find_node(root, ind - 1)->val;
        int curr_val = find_node(root, ind)->val;
        int next_val = find_node(root, ind + 1)->val;
        delete_node(root, ind + 1);
        delete_node(root, ind);
        delete_node(root, ind - 1);
        prev_val += curr_val - remain;
        curr_val = remain + next_val;
        insert(root, ind - 1, prev_val, rand());
        insert(root, ind, curr_val, rand());
        insert(root, 0, 0, rand());
        freq_0 = 0;
      }
    }
  }

  long long ans = 0;
  for(int i = 1; i <= MAX_H; i++) {
    ans += (1LL * i * (i - 1))/2 * find_node(root, i)->val;
  }
  cout << ans << endl;
}
