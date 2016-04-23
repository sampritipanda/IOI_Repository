#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct node {
  node * _left, * _right;
  int sum;
  int ans;
  int lazy;
  bool update = false;

  void clear() {
    _left = NULL;
    _right = NULL;
    sum = ans = lazy = 0;
    update = false;
  }

  node() {
    clear();
  }

  node * left() {
    if(_left == NULL) _left = new node;
    return _left;
  }

  node * right() {
    if(_right == NULL) _right = new node;
    return _right;
  }

  void propagate(int L, int R) {
    if(!update) return;

    sum = lazy * (R - L + 1);
    ans = max(lazy * 1, lazy * (R - L + 1));

    if(L < R) {
      left()->lazy = lazy; left()->update = true;
      right()->lazy = lazy; right()->update = true;
    }

    update = false;
    lazy = 0;
  }
};

void update(int L, int R, node* N, int qL, int qR, int D) {
  N->propagate(L, R);

  if(L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    N->lazy = D;
    N->update = true;
    N->propagate(L, R);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, N->left(), qL, qR, D);
  update(mid + 1, R, N->right(), qL, qR, D);

  // merge
  N->ans = max(N->left()->ans, N->left()->sum + N->right()->ans);
  N->sum = N->left()->sum + N->right()->sum;
}

int query(int L, int R, node* N, int H) {
  N->propagate(L, R);

  if(L == R) return L;

  int mid = (L + R)/2;
  N->left()->propagate(L, mid);
  if(N->left()->ans > H)
    return query(L, mid, N->left(), H);
  else
    return query(mid + 1, R, N->right(), H - N->left()->sum);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  node* root = new node;

  while(true) {
    char t; cin >> t;

    if(t == 'I') {
      int a, b; int D; cin >> a >> b >> D;
      update(0, N + 1, root, a, b, D);
    }
    else if(t == 'Q') {
      int H; cin >> H;
      cout << query(0, N + 1, root, H) - 1 << endl;
    }
    else break;
  }
}
