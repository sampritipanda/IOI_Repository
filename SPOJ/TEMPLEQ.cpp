#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int max_bit;
vector<pair<int, int> > temp;
int A[100001];
int bit[100001];
int ind[100001];   // ind[i] = Position of A[i] in sorted array
int rev[100001];   // rev[i] = Position of S[i] in actual array

int query(int i) {
  int sum = 0;
  while(i > 0) {
    sum += bit[i];
    i -= i & -i;
  }
  return sum;
}

void update(int i, int x) {
  while(i <= N) {
    bit[i] += x;
    i += i & -i;
  }
}

int find_highest(int x) {
  int range = 1 << max_bit;
  int id = 0;

  while(range > 0 && id < N) {
    int test = id + range;
    if(test <= N && x >= bit[test]) {
      x -= bit[test];
      id = test;
    }
    range >>= 1;
  }

  return id;
}

int main() {

  int Q; scanf("%d %d", &N, &Q);
  max_bit = int(log2(N));

  temp.resize(N);

  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    temp[i - 1] = {x, i};
  }
  sort(temp.begin(), temp.end());

  for(int i = 1; i <= N; i++) {
    auto curr = temp[i - 1];
    A[i] = curr.first;
    ind[curr.second] = i;
    rev[i] = curr.second;
  }

  for(int i = 1; i <= N; i++) update(i, A[i] - A[i - 1]);

  while(Q--) {
    int type; scanf("%d", &type);

    if(type == 1) {
      int x; scanf("%d", &x);
      int val = query(ind[x]);
      int inc_ind = find_highest(val);
      int x2 = rev[inc_ind];
      rev[ind[x]] = x2; rev[inc_ind] = x;
      swap(ind[x], ind[x2]);

      update(inc_ind, 1);
      update(inc_ind + 1, -1);
    }
    else if(type == 2) {
      int X; scanf("%d", &X);
      printf("%d\n", N - find_highest(X - 1));
    }
    else {
      int Y; scanf("%d", &Y);
      update(find_highest(Y - 1) + 1, -1);
    }
  }
}
