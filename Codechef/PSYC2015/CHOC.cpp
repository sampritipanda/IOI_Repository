// Chef and Chocolates 

#include <stdio.h>

long long* fenwick_tree;
int N;

long long query(int p){
  long long sum = 0;
  while(p > 0){
    sum += fenwick_tree[p];
    p -= p & -p;
  }
  return sum;
}

void update(int k, int v){
  while(k <= N){
    fenwick_tree[k] += v;
    k += k & -k;
  }
}

void range_update(int l, int r, int k){
  update(l, k);
  update(r + 1, -k);
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int u; scanf("%d %d", &N, &u);
    fenwick_tree = new long long[N + 1]();

    while(u--){
      int i, j, k; scanf("%d %d %d", &i, &j, &k);
      range_update(i + 1, j + 1, k);
    }

    int M; scanf("%d", &M);

    while(M--){
      int p; scanf("%d", &p);
      printf("%lld\n", query(p + 1));
    }
  }
}
