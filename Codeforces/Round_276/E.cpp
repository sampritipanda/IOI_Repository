#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

struct node {
  int pref, suff, ans, size;

  node() {
    pref = suff = ans = size = 0;
  }
};

node merge(node L, node R) {
  node N;
  N.ans = max(L.ans, R.ans);
  N.size = L.size + R.size;
  N.pref = L.pref; N.suff = R.suff;

  if(L.pref == L.size) N.pref = L.pref + R.pref;
  if(R.suff == R.size) N.suff = L.suff + R.suff;

  N.ans = max(N.ans, L.suff + R.pref);

  return N;
}

struct tree {
  tree *left, *right;
  node N;

  tree() {
    left = right = NULL;
    N = node();
  }

  void build_tree(int L, int R) {
    if(L == R) {
      N.size = 1;
      return;
    }

    int mid = (L + R)/2;

    left = new tree(); left->build_tree(L, mid);
    right = new tree(); right->build_tree(mid + 1, R);

    N = merge(left->N, right->N);
  }

  // sets value to 1
  tree* update(int L, int R, int x) {
    if(x < L || x > R) return this;

    tree* new_node = new tree();

    if(L == R) {
      new_node->N.ans = 1;
      new_node->N.pref = new_node->N.suff = 1;
      new_node->N.size = 1;

      return new_node;
    }

    int mid = (L + R)/2;
    new_node->left = left->update(L, mid, x);
    new_node->right = right->update(mid + 1, R, x);
    new_node->N = merge(new_node->left->N, new_node->right->N);

    return new_node;
  }

  node query(int L, int R, int qL, int qR) {
    if(L > qR || R < qL) return node();
    if(qL <= L && R <= qR) return N;

    int mid = (L + R)/2;

    return merge(left->query(L, mid, qL, qR), right->query(mid + 1, R, qL, qR));
  }
};

int H[100001];
vector<int> heights;
map<int, vector<int> > I;
tree* root[100002];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> H[i];

  for(int i = 1; i <= N; i++) {
    heights.push_back(H[i]);
    I[H[i]].push_back(i);
  }

  sort(heights.begin(), heights.end());
  heights.resize(unique(heights.begin(), heights.end()) - heights.begin());

  int M = heights.size();
  root[M] = new tree(); root[M]->build_tree(1, N);

  tree* curr_root = root[M];
  for(int i = M - 1; i >= 0; i--) {
    for(auto j: I[heights[i]]) {
      curr_root = curr_root->update(1, N, j);
    }
    root[i] = curr_root;
  }

  int Q; cin >> Q;

  while(Q--) {
    int L, R, W; cin >> L >> R >> W;

    int X = 0, Y = M - 1;
    while(X < Y) {
      int mid = (X + Y + 1)/2;

      if(root[mid]->query(1, N, L, R).ans >= W) {
        X = mid;
      }
      else {
        Y = mid - 1;
      }
    }

    assert(X >= 0 && X < M);
    cout << heights[X] << endl;
  }
}
