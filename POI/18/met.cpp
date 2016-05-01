#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct tree {
  int val;
  tree *left, *right;

  tree(int _val = 0, tree* _left = NULL, tree* _right = NULL) {
    val = _val;
    left = _left;
    right = _right;
  }

  void propagate(int L, int R) {
    if(L == R) return;

    left = new tree(left->val, left->left, left->right);
    right = new tree(right->val, right->left, right->right);

    left->val += val;
    right->val += val;

    val = 0;
  }

  void build_tree(int L, int R) {
    if(L == R) return;

    int mid = (L + R)/2;
    left = new tree; left->build_tree(L, mid);
    right = new tree; right->build_tree(mid + 1, R);
  }

  tree* update(int L, int R, int qL, int qR, int v) {
    propagate(L, R);

    if(L > qR || R < qL) return this;

    if(qL <= L && R <= qR) {
      tree* new_node = new tree(val, left, right);
      new_node->val += v;
      new_node->propagate(L, R);
      return new_node;
    }

    tree* new_node = new tree(val);
    int mid = (L + R)/2;
    new_node->left = left->update(L, mid, qL, qR, v);
    new_node->right = right->update(mid + 1, R, qL, qR, v);

    return new_node;
  }

  int query(int L, int R, int x) {
    propagate(L, R);

    if(L == R) return val;

    int mid = (L + R)/2;
    if(x <= mid) {
      return left->query(L, mid, x);
    }
    else {
      return right->query(mid + 1, R, x);
    }
  }
};

int O[300001];
int P[300001];
tree* root[300001];
vector<int> I[300001];

int main() {
  int N, M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= M; i++) {
    scanf("%d", &O[i]);
    I[O[i]].push_back(i);
  }

  for(int i = 1; i <= N; i++) scanf("%d", &P[i]);

  root[0] = new tree; root[0]->build_tree(1, M);

  int K; scanf("%d", &K);
  for(int i = 1; i <= K; i++) {
    int L, R, A; scanf("%d %d %d", &L, &R, &A);
    if(L > R) {
      root[i] = root[i - 1]->update(1, M, L, M, A);
      root[i] = root[i]->update(1, M, 1, R, A);
    }
    else {
      root[i] = root[i - 1]->update(1, M, L, R, A);
    }
  }

  for(int i = 1; i <= N; i++) {
    int L = 1, R = K + 1;
    while(L < R) {
      int mid = (L + R)/2;

      int samples = 0;
      for(int j = 0; j < I[i].size(); j++) {
        samples += root[mid]->query(1, M, I[i][j]);
      }
      if(samples >= P[i]) {
        R = mid;
      }
      else {
        L = mid + 1;
      }
    }
    if(L == K + 1) printf("NIE\n");
    else printf("%d\n", L);
  }
}
