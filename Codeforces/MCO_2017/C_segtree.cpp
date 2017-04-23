#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

struct node {
  int cnt = 0; // number of ones in range
  int ind = INT_MAX/2; // index of left most one
  bool lazy = false; // true => there was an update setting this whole range to 1, false = nothing
  node *left = NULL, *right = NULL;
};
int N, M;
map<int, vector<int> > rows;

inline void set_lazy(node*& root) {
  if(root == NULL) root = new node();
  root->lazy = true;
}

void propagate(node*& root, int L, int R) {
  if(root == NULL) root = new node();
  if(!root->lazy) return;

  root->cnt = R - L + 1;
  root->ind = L;

  if(L != R) {
    set_lazy(root->left);
    set_lazy(root->right);
  }

  root->lazy = false;
}

void update_set_1(node*& root, int L, int R, int qL, int qR) {
  if(root == NULL) root = new node();
  propagate(root, L, R);
  if(L > qR || R < qL) return;
  if(qL <= L && R <= qR) {
    root->lazy = true;
    propagate(root, L, R);
    return;
  }

  int mid = (L + R)/2;
  update_set_1(root->left, L, mid, qL, qR);
  update_set_1(root->right, mid + 1, R, qL, qR);
  root->cnt = root->left->cnt + root->right->cnt;
  root->ind = min(root->left->ind, root->right->ind);
}

node query(node*& root, int L, int R, int qL, int qR) {
  if(L > qR || R < qL) return node();
  propagate(root, L, R);
  if(qL <= L && R <= qR) return *root;

  int mid = (L + R)/2;
  node left = query(root->left, L, mid, qL, qR);
  node right = query(root->right, mid + 1, R, qL, qR);
  node ans;
  ans.cnt = left.cnt + right.cnt;
  ans.ind = min(left.ind, right.ind);
  return ans;
}

void update_set_0(node*& root, int L, int R, int i) {
  if(root == NULL) root = new node();
  propagate(root, L, R);
  if(i < L || i > R) return;

  if(L == R) {
    root->cnt = 0;
    root->ind = INT_MAX/2;
    return;
  }

  int mid = (L + R)/2;
  update_set_0(root->left, L, mid, i);
  update_set_0(root->right, mid + 1, R, i);
  root->cnt = root->left->cnt + root->right->cnt;
  root->ind = min(root->left->ind, root->right->ind);
}

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++) {
    int x, y; scanf("%d %d", &x, &y);
    rows[x].push_back(y);
  }

  for(auto& it: rows) {
    sort(it.second.begin(), it.second.end());
  }

  node* root = new node;
  update_set_1(root, 1, N, 1, 1);

  long long ans = 0;
  int prev_row = 0;
  for(auto it = rows.begin(); it != rows.end(); it++) {
    int i = it->first;
    if(i - prev_row > 1) {
      update_set_1(root, 1, N, root->ind, N);
      ans += 1LL * root->cnt * (i - prev_row - 1);
    }

    int prev_col = 0;
    for(int j: it->second) {
      update_set_1(root, 1, N, query(root, 1, N, prev_col + 1, j - 1).ind, j - 1);
      update_set_0(root, 1, N, j);
      prev_col = j;
    }
    if(prev_col < N) {
      update_set_1(root, 1, N, query(root, 1, N, prev_col + 1, N).ind, N);
    }
    ans += root->cnt;
    prev_row = i;
  }
  if(prev_row < N) {
    update_set_1(root, 1, N, root->ind, N);
    ans += 1LL * root->cnt * (N - prev_row);
  }

  printf("%lld\n", ans);
}
