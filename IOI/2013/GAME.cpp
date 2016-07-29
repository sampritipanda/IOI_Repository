#include <cstdio>
#include <algorithm>

using namespace std;

int cnt = 0;
int cnt2 = 0;

long long gcd(long long X, long long Y) {
  long long tmp;
  while (X != Y && Y != 0) {
    tmp = X;
    X = Y;
    Y = tmp % Y;
  }
  return X;
}

inline long long gcd(long long X, long long Y, long long Z) {
  return gcd(X, gcd(Y, Z));
}

struct node2 {
  node2 *left, *mid, *right;
  long long val;

  node2(long long _val = 0, node2 *_left = NULL, node2 *_mid = NULL, node2 *_right = NULL) {
    cnt2++;
    val = _val;
    left = _left;
    mid = _mid;
    right = _right;
  }
};

struct node {
  node *left, *mid, *right;
  node2 *val;

  node(node2 *_val = NULL, node *_left = NULL, node *_mid = NULL, node *_right = NULL) {
    cnt++;
    val = _val;
    left = _left;
    mid = _mid;
    right = _right;
  }
};

int R, C;

void update2(node2 *& root, int L, int R, int Q, long long K) {
  if(root == NULL) root = new node2();

  if(L == R) {
    root->val = K;
    return;
  }

  int mid1 = L + (R - L + 1)/3;
  int mid2 = R - (R - L + 1)/3;
  if(Q <= mid1) {
    update2(root->left, L, mid1, Q, K);
  }
  else if(Q <= mid2) {
    update2(root->mid, mid1 + 1, mid2, Q, K);
  }
  else {
    update2(root->right, mid2 + 1, R, Q, K);
  }
  root->val = gcd(root->left == NULL ? 0 : root->left->val,
                  root->mid == NULL ? 0 : root->mid->val,
                  root->right == NULL ? 0 : root->right->val);
}

void merge(node2*& root, node2* left, node2* mid, node2* right, int L, int R, int Q) {
  if(root == NULL) root = new node2();

  long long left_val = (left == NULL ? 0 : left->val);
  long long mid_val = (mid == NULL ? 0 : mid->val);
  long long right_val = (right == NULL ? 0 : right->val);

  root->val = gcd(left_val, mid_val, right_val);

  if(L == R) return;

  int mid1 = L + (R - L + 1)/3;
  int mid2 = R - (R - L + 1)/3;
  if (Q <= mid1) {
    merge(root->left,
        (left == NULL ? NULL : left->left),
        (mid == NULL ? NULL : mid->left),
        (right == NULL ? NULL : right->left),
        L, mid1, Q);
  }
  else if(Q <= mid2) {
    merge(root->mid,
        (left == NULL ? NULL : left->mid),
        (mid == NULL ? NULL : mid->mid),
        (right == NULL ? NULL : right->mid),
        mid1 + 1, mid2, Q);
  }
  else {
    merge(root->right,
        (left == NULL ? NULL : left->right),
        (mid == NULL ? NULL : mid->right),
        (right == NULL ? NULL : right->right),
        mid2 + 1, R, Q);
  }
}

void update(node *& root, int L, int R, int P, int Q, long long K) {
  if(root == NULL) root = new node();

  if(L == R) {
    update2(root->val, 0, C - 1, Q, K);
    return;
  }

  int mid1 = L + (R - L + 1)/3;
  int mid2 = R - (R - L + 1)/3;
  if(P <= mid1) {
    update(root->left, L, mid1, P, Q, K);
  }
  else if (P <= mid2) {
    update(root->mid, mid1 + 1, mid2, P, Q, K);
  }
  else {
    update(root->right, mid2 + 1, R, P, Q, K);
  }
  merge(root->val,
      (root->left == NULL ? NULL : root->left->val),
      (root->mid == NULL ? NULL : root->mid->val),
      (root->right == NULL ? NULL : root->right->val),
      0, C - 1, Q);
}

long long query2(node2* root, int L, int R, int C_L, int C_R) {
  if(root == NULL) return 0;
  if(L > R) return 0;
  if(C_L > R || C_R < L) return 0;

  if(C_L <= L && R <= C_R) return root->val;

  int mid1 = L + (R - L + 1)/3;
  int mid2 = R - (R - L + 1)/3;

  long long left = query2(root->left, L, mid1, C_L, C_R);
  long long mid = query2(root->mid, mid1 + 1, mid2, C_L, C_R);
  long long right = query2(root->right, mid2 + 1, R, C_L, C_R);
  return gcd(left, mid, right);
}

long long query(node* root, int L, int R, int R_L, int R_R, int C_L, int C_R) {
  if(root == NULL) return 0;
  if(R_L > R || R_R < L) return 0;

  if(R_L <= L && R <= R_R) return query2(root->val, 0, C - 1, C_L, C_R);

  int mid1 = L + (R - L + 1)/3;
  int mid2 = R - (R - L + 1)/3;

  long long left = query(root->left, L, mid1, R_L, R_R, C_L, C_R);
  long long mid = query(root->mid, mid1 + 1, mid2, R_L, R_R, C_L, C_R);
  long long right = query(root->right, mid2 + 1, R, R_L, R_R, C_L, C_R);
  return gcd(left, mid, right);
}

int main() {
  int N; scanf("%d %d %d", &R, &C, &N);

  node* root = NULL;

  while(N--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int P, Q; long long K; scanf("%d %d %lld", &P, &Q, &K);
      update(root, 0, R - 1, P, Q, K);
    }
    else {
      int P, Q, U, V; scanf("%d %d %d %d", &P, &Q, &U, &V);
      printf("%lld\n", query(root, 0, R - 1, P, U, Q, V));
    }
  }

  fprintf(stderr, "%d %d\n", cnt, cnt2);
}
