#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct node {
  long long max = 0;
  long long curr = 0;
  long long lazy_max = 0, lazy_add = 0;
};

vector<pair<int, int> > queries[100001];
long long A[100001];
vector<int> I[200001];
node segtree[400004];
long long ans[100001];

void propagate(int L, int R, int i) {
  segtree[i].max = max(segtree[i].max, segtree[i].curr + segtree[i].lazy_max);
  segtree[i].curr += segtree[i].lazy_add;

  if(L != R) {
    segtree[2*i + 1].lazy_max = max(segtree[2*i + 1].lazy_max, segtree[2*i + 1].lazy_add + segtree[i].lazy_max);
    segtree[2*i + 1].lazy_add += segtree[i].lazy_add;

    segtree[2*i + 2].lazy_max = max(segtree[2*i + 2].lazy_max, segtree[2*i + 2].lazy_add + segtree[i].lazy_max);
    segtree[2*i + 2].lazy_add += segtree[i].lazy_add;
  }

  segtree[i].lazy_add = 0;
  segtree[i].lazy_max = 0;
}

node merge(node L, node R) {
  node N;
  N.max = max(L.max, R.max);
  N.curr = max(L.curr, R.curr);

  return N;
}

void update(int L, int R, int i, int qL, int qR, long long val) {
  propagate(L, R, i);

  if(L > R || R < qL || L > qR) return;

  if(qL <= L && R <= qR) {
    segtree[i].lazy_add += val;
    segtree[i].lazy_max = max(segtree[i].lazy_max, val);

    propagate(L, R, i);

    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, val); update(mid + 1, R, 2*i + 2, qL, qR, val);

  long long temp_max = segtree[i].max;
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
  segtree[i].max = max(segtree[i].max, temp_max);
}

node query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > R || R < qL || L > qR) return node();

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;

  return merge(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

  int Q; scanf("%d", &Q);

  for(int i = 0; i < Q; i++) {
    int L, R; scanf("%d %d", &L, &R);
    queries[R].push_back({L, i});
  }

  for(int i = 1; i <= N; i++) {
    int prev;
    if(I[A[i] + 100000].empty()) prev = 0;
    else prev = I[A[i] + 100000].back();

    update(1, N, 0, prev + 1, i, A[i]);

    I[A[i] + 100000].push_back(i);

    for(auto q: queries[i]) {
      int L = q.first, ind = q.second;

      long long curr_ans = query(1, N, 0, L, i).max;
      ans[ind] = curr_ans;
    }
  }

  for(int i = 0; i < Q; i++) {
    printf("%lld\n", ans[i]);
  }
}
