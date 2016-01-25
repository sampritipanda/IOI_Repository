#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  long long ans;
  vector<long long> T;
};

int N;
int A[50001];
node segtree[50001 * 4];

node merge(node& L, node& R) {
  node curr;
  merge(L.T.begin(), L.T.end(), R.T.begin(), R.T.end(), curr.T.begin(), curr.T.end());
  curr.ans = 0;
  for(int i = 1; i < curr.T.size(); i++) {
    curr.ans += (curr.T[i] - curr.T[i - 1]) * (curr.T[i] - curr.T[i - 1]);
  }
  return curr;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    node curr;
    curr.ans = 0;
    curr.T = {A[L]};
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1); build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int A, int B, int i) {
  if(L > R) return node();
  if(L > B || R < A) return node();

  if(A <= L && R <= B) return segtree[i];
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  build_tree(0, N - 1, 0);
}
