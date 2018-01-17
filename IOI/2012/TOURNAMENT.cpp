#include <cstdio>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, C, pop_rank;
int A[100000];
int S[100000], E[100000];
vector<int> sweep_list[100000][2];
int max_segtree[400000];
int query_cache[100000];

void build(int L, int R, int i) {
  if(L == R) {
    max_segtree[i] = A[L];
    return;
  }

  int mid = (L + R)/2;
  build(L, mid, 2*i + 1);
  build(mid + 1, R, 2*i + 2);
  max_segtree[i] = max(max_segtree[2*i + 1], max_segtree[2*i + 2]);
}

int query(int L, int R, int i, int qL, int qR) {
  if(qL > R || qR < L) return 0;
  if(qL <= L && R <= qR) return max_segtree[i];

  int mid = (L + R)/2;
  return max(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

int main() {
  scanf("%d %d %d", &N, &C, &pop_rank);

  for(int i = 0; i < N - 1; i++) scanf("%d", &A[i]);

  ordered_set start_set, end_set;
  for(int i = 0; i < N; i++) {
    start_set.insert(i);
    end_set.insert(i);
  }

  for(int i = 0; i < C; i++) {
    int s, e; scanf("%d %d", &s, &e);
    auto L_it = start_set.find_by_order(s);
    auto R_it = end_set.find_by_order(e);

    S[i] = *L_it; E[i] = *R_it;
    sweep_list[S[i]][0].push_back(i);
    sweep_list[E[i]][1].push_back(i);

    for(int j = e; j >= s + 1; j--) {
      start_set.erase(start_set.find_by_order(j));
    }
    for(int j = e - 1; j >= s; j--) {
      end_set.erase(end_set.find_by_order(j));
    }
  }

  build(0, N - 2, 0);

  for(int i = 0; i < C; i++) {
    query_cache[i] = query(0, N - 2, 0, S[i], E[i] - 1);
  }

  int ans = -1, ans_id = -1;
  ordered_set battles;

  for(int i = 0; i < N; i++) {
    for(int j: sweep_list[i][0]) {
      battles.insert(j);
    }

    int L = -1, R = battles.size() - 1;
    while(L < R) {
      int mid = (L + R + 1)/2;
      int battle_id = *battles.find_by_order(mid);

      if(pop_rank > query_cache[battle_id]) {
        L = mid;
      }
      else {
        R = mid - 1;
      }
    }

    if((L + 1) > ans) {
      ans = L + 1;
      ans_id = i;
    }

    for(int j: sweep_list[i][1]) {
      battles.erase(j);
    }
  }

  printf("%d\n", ans_id);
}
