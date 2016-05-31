#include <cstdio>
#include <algorithm>
#include <deque>
#include <map>
#include <vector>

using namespace std;

pair<int, int> merge(pair<int, int> L, pair<int, int> R) {
  if(R.first >= L.first) {
    return R;
  }
  else {
    return L;
  }
}

struct node {
  pair<int, int> info;
  node *left, *right;

  node(int _val = 0, int _id = 0) {
    info = make_pair(_val, _id);
    left = NULL;
    right = NULL;
  }

  void build_tree(int L, int R) {
    if(L == R) {
      info = make_pair(0, L);
      return;
    }

    int mid = (L + R)/2;
    left = new node(); left->build_tree(L, mid);
    right = new node(); right->build_tree(mid + 1, R);
  }

  node* update(int L, int R, int x, int v) {
    if(x < L || x > R) return this;

    node* new_node = new node();
    if(L == R) {
      new_node->info = make_pair(v, L);
    }
    else {
      int mid = (L + R)/2;
      if(x <= mid) {
        new_node->left = left->update(L, mid, x, v);
        new_node->right = right;
      }
      else {
        new_node->left = left;
        new_node->right = right->update(mid + 1, R, x, v);
      }
      new_node->info = merge(new_node->left->info, new_node->right->info);
    }

    return new_node;
  }

  pair<int, int> query(int L, int R, int qL, int qR) {
    if(L > qR || R < qL) return make_pair(0, 0);
    if(qL <= L && R <= qR) return info;

    int mid = (L + R)/2;
    return merge(left->query(L, mid, qL, qR), right->query(mid + 1, R, qL, qR));
  }
};

int D[1000001];
int dp[1000001];
deque<int> DQ;
node* root[1000001];
map<int, int> compres;
vector<int> I[1000001];

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &D[i]);
    compres[D[i]];
  }
  int timer = 0;
  for(map<int, int>::iterator it = compres.begin(); it != compres.end(); it++) {
    compres[it->first] = ++timer;
  }
  for(int i = 1; i <= N; i++) D[i] = compres[D[i]];
  for(int i = 1; i <= N; i++) I[D[i]].push_back(i);

  root[0] = new node(); root[0]->build_tree(1, N);
  node* curr_root = root[0];
  for(int i = 1; i <= N; i++) {
    for(int id = 0; id < I[i].size(); id++) {
      int j = I[i][id];
      curr_root = curr_root->update(1, N, j, i);
    }
    root[i] = curr_root;
  }

  int Q; scanf("%d", &Q);

  while(Q--) {
    int K; scanf("%d", &K);

    DQ.clear();
    dp[N] = 0;
    DQ.push_back(N);

    for(int i = N - 1; i >= 1; i--) {
      while(DQ.front() > i + K) DQ.pop_front();
      int mx = DQ.front();

      if(D[mx] < D[i]) dp[i] = dp[mx];
      else {
        dp[i] = 1 + dp[mx];

        pair<int, int> info = root[D[i] - 1]->query(1, N, i, min(i + K, N));
        if(info.first) dp[i] = min(dp[i], dp[info.second]);
      }

      while(!DQ.empty() && D[i] > D[DQ.back()]) DQ.pop_back();
      DQ.push_back(i);
    }

    printf("%d\n", dp[1]);
  }
}
