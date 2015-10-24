#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int H[100001];
int temp_H[100001];
long long segtree[400004];
long long lazy[400004];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = H[L];
    return;
  }

  int mid = L + (R - L)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2 * i + 2);
  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

void propagate(int L, int R, int i) {
  if(lazy[i] > 0) {
    long long change = lazy[i] * (R - L + 1);
    if(segtree[i] < change) segtree[i] = 0;
    else segtree[i] -= change;

    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }

    lazy[i] = 0;
  }
}

long long query(int L, int R, int qS, int qE, int i) {
  if(L > R) return 0;

  if(L > qE || R < qS) return 0;

  propagate(L, R, i);

  if(qS <= L && R <= qE) return segtree[i];

  int mid = L + (R - L)/2;
  return query(L, mid, qS, qE, 2*i + 1) + query(mid + 1, R, qS, qE, 2*i + 2);
}

void update(int L, int R, int qS, int qE, int i) {
  if(L > R) return;

  propagate(L, R, i);

  if(L > qE || R < qS) return;

  if(qS <= L && R <= qE) {
    lazy[i] += 1;
    propagate(L, R, i);
    return;
  }

  int mid = L + (R - L)/2;
  update(L, mid, qS, qE, 2*i + 1);
  update(mid + 1, R, qS, qE, 2*i + 2);

  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> H[i];
  for(int i = 1; i <= N; i++) temp_H[i] = H[i];

  memset(segtree, 0, sizeof segtree);
  memset(lazy, 0, sizeof lazy);

  int time;
  int L = 1, R = N;
  for(time = 1; time <= 2000; time++) {
    H[L] = 0; H[R] = 0;
    L++; R--;
    for(int i = L; i <= R; i++) {
      if(H[i] > 0) H[i] -= max(1, max(temp_H[i] - temp_H[i - 1], temp_H[i] - temp_H[i + 1]));
    }
    long long sum = 0;
    for(int i = 1; i <= N; i++) sum += H[i];
    if(sum == 0) {
      cout << time << endl;
      return 0;
    }

    for(int i = 1; i <= N; i++) temp_H[i] = H[i];
  }

  time--;

  build_tree(1, N, 0);

  while(query(1, N, L, R, 0) > 0) {
    time++;
    L++; R--;
    update(1, N, L, R, 0);
  }
  cout << time << endl;
}
