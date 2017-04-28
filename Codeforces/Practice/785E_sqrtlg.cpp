#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;
const int MAX = 200000;
const int BLOCK_SIZE = 1000;
int A[MAX_N + 1];
int bit[MAX_N/BLOCK_SIZE + 1][MAX + 1];
int N;

void update(int *bit, int i, int v) {
  if(i == 0) return;
  while(i <= MAX) {
    bit[i] += v;
    i += i & -i;
  }
}

int query(int *bit, int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int find_inversions(int X) {
  int ans = 0;

  for(int i = 0; i < X/BLOCK_SIZE; i++) {
    ans += BLOCK_SIZE - query(bit[i], A[X]);
  }
  for(int i = X/BLOCK_SIZE * BLOCK_SIZE; i < X; i++) {
    if(A[i] > A[X]) ans++;
  }
  for(int i = X + 1; i < (X/BLOCK_SIZE + 1) * BLOCK_SIZE; i++) {
    if(A[i] < A[X]) ans++;
  }
  for(int i = X/BLOCK_SIZE + 1; i < N/BLOCK_SIZE + 1; i++) {
    ans += query(bit[i], A[X] - 1);
  }

  return ans;
}

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; i++) A[i] = i + 1;

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    update(bit[i/BLOCK_SIZE], A[i], 1);
  }

  int M; scanf("%d", &M);

  while(M--) {
    int i, j; scanf("%d %d", &i, &j); i--, j--;

    ans -= find_inversions(i);
    update(bit[i/BLOCK_SIZE], A[i], -1);
    int temp = A[i];
    A[i] = A[j];
    update(bit[i/BLOCK_SIZE], A[i], 1);
    ans += find_inversions(i);

    ans -= find_inversions(j);
    update(bit[j/BLOCK_SIZE], A[j], -1);
    A[j] = temp;
    update(bit[j/BLOCK_SIZE], A[j], 1);
    ans += find_inversions(j);

    printf("%lld\n", ans);
  }
}
