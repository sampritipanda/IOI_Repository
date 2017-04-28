#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 200000;
int N;
int A[MAX_N + 1];
ordered_set bit[MAX_N + 1];

void insert(int i, int v) {
  while(i <= N) {
    bit[i].insert(v);
    i += i & -i;
  }
}

void remove(int i, int v) {
  while(i <= N) {
    bit[i].erase(v);
    i += i & -i;
  }
}

// find count of numbers in [1, qR] < v
int query(int i, int v) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i].order_of_key(v);
    i -= i & -i;
  }
  return ans;
}

int main() {
  scanf("%d", &N);

  for(int i = 1; i <= N; i++) A[i] = i;

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    insert(i, A[i]);
  }

  int M; scanf("%d", &M);

  while(M--) {
    int i, j; scanf("%d %d", &i, &j);
    if(i > j) swap(i, j);

    ans -= query(j, A[i]) - query(i - 1, A[i]);
    ans += query(j, A[j] + 1) - query(i - 1, A[j] + 1);
    if(A[i] > A[j]) ans++;

    remove(i, A[i]);
    remove(j, A[j]);
    swap(A[i], A[j]);
    insert(i, A[i]);
    insert(j, A[j]);

    ans += query(j, A[i]) - query(i - 1, A[i]);
    ans -= query(j, A[j] + 1) - query(i - 1, A[j] + 1);
    if(A[i] > A[j]) ans--;

    printf("%lld\n", ans);
  }
}
