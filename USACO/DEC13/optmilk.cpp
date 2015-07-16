#include <iostream>
#include <algorithm>

using namespace std;

int N, D;
int M[50000];

long long segtree_1[300000];
long long segtree_2[300000];
long long segtree_3[300000];
long long segtree_4[300000];

void merge(int parent, int left, int right) {
  segtree_1[parent] = max(segtree_1[left] + segtree_1[right], segtree_4[left] + max(segtree_3[right], segtree_1[right]));
  segtree_2[parent] = max(segtree_3[left] + segtree_4[right], segtree_2[left] + max(segtree_2[right], segtree_4[right]));
  segtree_3[parent] = max(segtree_3[left] + segtree_1[right], segtree_2[left] + max(segtree_3[right], segtree_1[right]));
  segtree_4[parent] = max(segtree_1[left] + segtree_4[right], segtree_4[left] + max(segtree_2[right], segtree_4[right]));
}

void buildTree(int L, int R, int i) {
  if(L == R) {
    segtree_1[i] = 0;
    segtree_2[i] = 0;
    segtree_3[i] = M[L];
    segtree_4[i] = 0;
  }
  else {
    int mid = L + (R - L)/2;
    buildTree(L, mid, 2*i + 1);
    buildTree(mid + 1, R, 2*i + 2);
    merge(i, 2*i + 1, 2*i + 2);
  }
}

void updateTree(int L, int R, int i, int index, int value) {
  if(L > index || R < index) return;

  if(L == R) {
    M[L] = value;
    segtree_3[i] = M[L];
  }
  else {
    int mid = L + (R - L)/2;
    updateTree(L, mid, 2*i + 1, index, value);
    updateTree(mid + 1, R, 2*i + 2, index, value);
    merge(i, 2*i + 1, 2*i + 2);
  }
}

int main() {
  freopen("optmilk.in", "r", stdin);
  freopen("optmilk.out", "w", stdout);

  scanf("%d %d", &N, &D);
  for(int i = 1; i <= N; i++) scanf("%d", &M[i]);

  buildTree(1, N, 0);

  long long max_milk = 0;

  while(D--) {
    int i, m; scanf("%d %d", &i, &m);
    updateTree(1, N, 0, i, m);
    max_milk += max(max(segtree_1[0], segtree_2[0]), max(segtree_3[0], segtree_4[0]));
  }

  printf("%lld\n", max_milk);
}
