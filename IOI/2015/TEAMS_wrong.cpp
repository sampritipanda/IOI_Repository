/* Failing case (77/100 tho)
10
1 4
1 4
1 4
1 4
2 2
2 2
2 3
2 3
2 3
2 3
1
4 1 2 3 4
*/


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX = 500000;

struct node {
  int val;
  node *left, *right;

  node(int _val = 0, node* _left = NULL, node* _right = NULL) {
    val = _val;
    left = _left;
    right = _right;
  }

  int query(int L, int R, int qL, int qR) {
    if(L > qR || R < qL) return 0;
    if(qL <= L && R <= qR) return val;

    int mid = (L + R)/2;
    return left->query(L, mid, qL, qR) + right->query(mid + 1, R, qL, qR);
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

int N;
vector<int> A[MAX + 1];
node* root[MAX + 1];
int org_req[MAX + 2];
int new_req[MAX + 2];
int K[200002];

inline int range_query(int xL, int xR, int yL, int yR) {
  xL = max(xL, 1);
  xR = min(xR, N);
  yL = max(yL, 1);
  yR = min(yR, N);

  if(xL > xR) return 0;
  if(yL > yR) return 0;

  return root[xR]->query(1, N, yL, yR) - root[xL - 1]->query(1, N, yL, yR);
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int x, y; scanf("%d %d", &x, &y);
    A[x].push_back(y);
  }

  root[0] = new node(); root[0]->build_tree(1, N);

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
    for(int i = 0; i < M; i++) org_req[K[i]] += K[i];
    M = unique(K, K + M) - K;
    K[M] = N + 1;

    bool pos = true;

    for(int i = 0; i < M; i++) {
      int k = K[i];
      int total = range_query(1, k, k, N);
      int req = org_req[k] + new_req[k];

      if(total < req) {
        pos = false;
        break;
      }

      int left, right;
      if(i == 0) {
        left = 0;
        right = range_query(1, k, k, K[i + 1] - 1);
      }
      else {
        left = range_query(1, K[i - 1], k, K[i + 1] - 1);
        right = range_query(K[i - 1] + 1, k, k, K[i + 1] - 1);
      }

      // cout << k << " " << total << " " << new_req[k] << " " << org_req[k] << " " << left << " " << right << endl;

      int temp;
      temp = min(new_req[k], left);
      new_req[k] -= temp;
      left -= temp;

      temp = min(org_req[k], left);
      org_req[k] -= temp;
      left -= temp;

      temp = min(org_req[k], right);
      org_req[k] -= temp;
      right -= temp;

      new_req[K[i + 1]] += org_req[k] + new_req[k];
    }
    if(new_req[N + 1] > 0) pos = false;

    if(pos) printf("1\n");
    else printf("0\n");

    for(int i = 0; i <= M; i++) org_req[K[i]] = new_req[K[i]] = 0;
  }
}
