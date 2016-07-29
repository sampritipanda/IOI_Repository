#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX = 1000000;

struct node {
  int val;
  node *points;
  node *left, *right;

  node(int _val = 0) {
    val = _val;
    left = NULL;
    right = NULL;
    points = NULL;
  }

  // increment
  node* update(int L, int R, int i) {
    if(i < L || i > R) return this;

    node* new_node = new node(val + 1);
    if(L < R) {
      int mid = (L + R)/2;
      new_node->left = left->update(L, mid, i);
      new_node->right = right->update(mid + 1, R, i);
    }
    return new_node;
  }

  void build_tree(int L, int R) {
    if(L == R) return;

    int mid = (L + R)/2;
    left = new node(); left->build_tree(L, mid);
    right = new node(); right->build_tree(mid + 1, R);
  }
};

node* root[MAX + 1];
int K[200002];

void propagate(node* N, int L, int R) {
  if(N->points == NULL) return;

  N->val = N->points->val;
  if(L < R) {
    N->left->points = N->points->left;
    N->right->points = N->points->right;
  }

  N->points = NULL;
}

int assign(node* points, node* used, int L, int R, int yL, int yR, int K) {
  propagate(used, L, R);

  if(L > yR || R < yL || K == 0) return 0;
  int avail = points->val - used->val;
  if(yL <= L && R <= yR && avail <= K) {
    used->points = points;
    propagate(used, L, R);
    return avail;
  }
  if(L == R || avail == 0) return 0;

  int mid = (L + R)/2;
  int left_used = assign(points->left, used->left, L, mid, yL, yR, K);
  int right_used = assign(points->right, used->right, mid + 1, R, yL, yR, max(K - left_used, 0));
  used->val = used->left->val + used->right->val;
  return left_used + right_used;
}

void clear(node* curr) {
  if(curr->val > 0 || curr->points != NULL) {
    if(curr->left != NULL) clear(curr->left);
    if(curr->right != NULL) clear(curr->right);
  }
  curr->val = 0; curr->points = NULL;
}

void output(node* curr, int L, int R) {
  assert(curr->val == 0);
  assert(curr->points == NULL);

  if(L == R) return;
  int mid = (L + R)/2;
  output(curr->left, L, mid);
  output(curr->right, mid + 1, R);
}

vector<int> A[MAX + 1];
vector<pair<int, int> > temp;
vector<int> Y;

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int x, y; scanf("%d %d", &x, &y);
    temp.push_back({y, x});
  }
  sort(temp.begin(), temp.end());
  int ptr = 0;
  for(auto it: temp) {
    int y = it.first, x = it.second;
    Y.push_back(y);
    A[x].push_back(++ptr);
  }

  root[0] = new node(); root[0]->build_tree(1, N);
  node* used = new node(); used->build_tree(1, N);

  for(int i = 1; i <= N; i++) {
    root[i] = root[i - 1];
    for(int y: A[i]) {
      root[i] = root[i]->update(1, N, y);
    }
  }

  int Q; scanf("%d", &Q);

  while(Q--) {
    int M; scanf("%d", &M);
    long long sum = 0;
    for(int i = 0; i < M; i++) {
      scanf("%d", &K[i]);
      sum += K[i];
    }

    if(sum > N) {
      printf("0\n");
      continue;
    }

    sort(K, K + M);
    clear(used);
    // output(used, 1, N);

    bool pos = true;
    for(int i = 0; i < M; i++) {
      int id = lower_bound(Y.begin(), Y.end(), K[i]) - Y.begin() + 1;
      int cnt = assign(root[K[i]], used, 1, N, id, N, K[i]);
      if(cnt < K[i]) {
        pos = false;
        break;
      }
    }

    if(pos) printf("1\n");
    else printf("0\n");
  }
}
