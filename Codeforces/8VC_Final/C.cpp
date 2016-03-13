#include <iostream>
#include <algorithm>

using namespace std;

int N, K, A, B;
int tree_A[800001];
int tree_B[800001];

void update(int L, int R, int i, int ind, int val) {
  if(L == R) {
    tree_A[i] = min(tree_A[i] + val, A);
    tree_B[i] = min(tree_B[i] + val, B);
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) update(L, mid, 2*i + 1, ind, val);
  else update(mid + 1, R, 2*i + 2, ind, val);

  // safety check
  tree_A[i] = tree_A[2*i + 1] + tree_A[2*i + 2];
  tree_B[i] = tree_B[2*i + 1] + tree_B[2*i + 2];
}

int query(int L, int R, int i, int qL, int qR, char type) {
  if(L > R) return 0;
  if(L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) {
    if(type == 'A') return tree_A[i];
    else return tree_B[i];
  }

  int mid = (L + R)/2;
  return query(L, mid, 2*i + 1, qL, qR, type) + query(mid + 1, R, 2*i + 2, qL, qR, type);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int Q;
  cin >> N >> K >> A >> B >> Q;

  while(Q--) {
    int type; cin >> type;

    if(type == 1) {
      int d, a; cin >> d >> a;
      update(1, N, 0, d, a);
    }
    else {
      int p; cin >> p;
      int ans = 0;
      ans += query(1, N, 0, 1, p - 1, 'B');
      ans += query(1, N, 0, p + K, N, 'A');

      cout << ans << endl;
    }
  }
}
