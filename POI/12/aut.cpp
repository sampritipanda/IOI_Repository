#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct node {
  int val;
  node *left, *right;

  node(int _val = 0) {
    val = _val;
    left = right = NULL;
  }
};

void update(int L, int R, node*& curr, int i, int v) {
  if(curr == NULL) curr = new node;
  curr->val = max(curr->val, v);

  if(L == R) return;

  int mid = (L + R)/2;
  if(i <= mid) {
    update(L, mid, curr->left, i, v);
  }
  else {
    update(mid + 1, R, curr->right, i, v);
  }
}

int query(int L, int R, node* curr, int qL, int qR) {
  if(L > qR || R < qL) return 0;
  if(curr == NULL) return 0;

  if(qL <= L && R <= qR) return curr->val;

  int mid = (L + R)/2;
  return max(query(L, mid, curr->left, qL, qR), query(mid + 1, R, curr->right, qL, qR));
}

map<int, set<int> > I;
map<pair<int, int>, int> P;
map<pair<int, int>, int> dp;

int main() {
  node* root = NULL;
  int N, M, K; scanf("%d %d %d", &N, &M, &K);

  while(K--) {
    int x, y, p; scanf("%d %d %d", &x, &y, &p);
    I[y].insert(x);
    P[make_pair(y, x)] = p;
  }
  I[M].insert(N);
  P[make_pair(M, N)] = 0;

  for(map<int, set<int> >::iterator it = I.begin(); it != I.end(); it++) {
    int x = it->first;
    for(set<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      int y = *it2;

      dp[make_pair(x, y)] = P[make_pair(x, y)] + query(1, N, root, 1, y);
      update(1, N, root, y, dp[make_pair(x, y)]);
    }
  }

  printf("%d\n", dp[make_pair(M, N)]);
}
