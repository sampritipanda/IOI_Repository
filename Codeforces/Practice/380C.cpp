#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct node {
  int X, Y, ans;
};

string S;
node segtree[4000000];

node merge(node L, node R) {
  int add_length = min(L.X, R.Y);
  node N = {L.X - add_length + R.X, L.Y + R.Y - add_length, L.ans + R.ans + 2*add_length};
  return N;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = {0, 0, 0};
    if(S[L] == '(') segtree[i].X++;
    else segtree[i].Y++;

    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int L, int R, int A, int B, int i) {
  if(L > R || L > B || R < A) return node();
  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid, A, B, 2*i + 1), query(mid + 1, R, A, B, 2*i + 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> S;

  int N = S.length();

  build_tree(0, N - 1, 0);

  int Q; cin >> Q;

  while(Q--) {
    int L, R; cin >> L >> R; L--; R--;
    cout << query(0, N - 1, L, R, 0).ans << endl;
  }
}
