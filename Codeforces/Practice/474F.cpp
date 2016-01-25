#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int A[100000];
int segtree[400000];
map<int, vector<int> > I;

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = A[L];
    return;
  }

  int mid = (L + R) >> 1;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = __gcd(segtree[2*i + 1], segtree[2*i + 2]);
}

int query(int L, int R, int A, int B, int i) {
  if(L > R || R < A || L > B) return 0;

  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R) >> 1;
  return __gcd(query(L, mid, A, B, 2*i + 1), query(mid + 1, R, A, B, 2*i + 2));
}

int count(int L, int R, int x) {
  auto j = upper_bound(I[x].begin(), I[x].end(), R);
  auto i = lower_bound(I[x].begin(), I[x].end(), L);
  return j - i;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  build_tree(0, N - 1, 0);

  for(int i = 0; i < N; i++) {
    I[A[i]].push_back(i);
  }

  int Q; cin >> Q;

  while(Q--) {
    int L, R; cin >> L >> R; L--; R--;
    int g = query(0, N - 1, L, R, 0);

    cout << R - L + 1 - count(L, R, g) << endl;
  }
}
