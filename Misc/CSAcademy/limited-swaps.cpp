#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
int A[100001];
pair<int, int> segtree[400001];
int bit[100001];

pair<int, int> merge(pair<int, int> L, pair<int, int> R) {
  if(L.first >= R.first) {
    return L;
  }
  else {
    return R;
  }
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = {A[L], L};
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

pair<int, int> query(int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL || L > R) return {INT_MIN/2, 100001};
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return merge(query(L, mid , 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

void update(int L, int R, int i, int ind, int val) {
  if(L == R) {
    segtree[i] = {val, L};
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind, val);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind, val);
  }
  segtree[i] = merge(segtree[2*i + 1], segtree[2*i + 2]);
}

int bit_query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void bit_update(int i, int v) {
  if(i == 0) return;
  while(i <= 100000) {
    bit[i] += v;
    i += i & -i;
  }
}

inline int bit_query(int L, int R) {
  return bit_query(R) - bit_query(L - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N; long long K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i];

    build_tree(1, N, 0);

    for(int i = 1; i <= N; ) {
        if(bit_query(i, i) == 1) {
          i++;
          continue;
        }
        int L = i;
        int R_L = L, R_R = N;
        while(R_L < R_R) {
          int mid = (R_L + R_R + 1)/2;
          if((mid - L) - bit_query(L, mid) <= K) {
            R_L = mid;
          }
          else {
            R_R = mid - 1;
          }
        }
        int R = R_L;

        auto it = query(1, N, 0, L, R);
        int max_val = it.first, max_ind = it.second;

        if(max_ind == i) {
          cout << A[i] << " ";
          i++;
          continue;
        }

        cout << max_val << " ";

        K -= (max_ind - i) - bit_query(i, max_ind);
        update(1, N, 0, max_ind, INT_MIN/2);
        bit_update(max_ind, 1);
    }

    cout << endl;
}
