// Big Top

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int X[800001], H[800001];
set<pair<int, int> > X_left_set;
int H_map[10000001];
long double area_map[10000001];
int segtree_right[40000004];
int segtree_left[40000004];

int query(int* segtree, int L, int R, int i, int qL, int qR) {
  if(L > R) return INT_MIN/2;
  if(L > qR || R < qL) return INT_MIN/2;

  if(qL <= L && R <= qR) {
    return segtree[i];
  }

  int mid = (L + R)/2;
  return max(query(segtree, L, mid, 2*i + 1, qL, qR), query(segtree, mid + 1, R, 2*i + 2, qL, qR));
}

void update(int* segtree, int L, int R, int i, int p, int v) {
  if(p > R || p < L) return;

  segtree[i] = max(segtree[i], v);

  if(L == R) return;
  int mid = (L + R)/2;
  update(segtree, L, mid, 2*i + 1, p, v);
  update(segtree, mid + 1, R, 2*i + 2, p, v);
}

int main() {
  int T; scanf("%d", &T);

  for(int t = 1; t <= T; t++) {
    for(int i = 0; i <= 40000000; i++) {
      segtree_right[i] = segtree_left[i] = INT_MIN/2;
    }
    for(int i = 0; i <= 10000000; i++) H_map[i] = 0;
    X_left_set.clear();

    int N; scanf("%d", &N);

    long long A_x, B_x, C_x;
    scanf("%d %lld %lld %lld", &X[1], &A_x, &B_x, &C_x);
    for(int i = 2; i <= N; i++) {
      X[i] = ((A_x * X[i - 1] + B_x) % C_x) + 1;
    }

    long long A_h, B_h, C_h;
    scanf("%d %lld %lld %lld", &H[1], &A_h, &B_h, &C_h);
    for(int i = 1; i <= N; i++) {
      H[i] = ((A_h * H[i - 1] + B_h) % C_h) + 1;
    }

    // for(int i = 1; i <= N; i++) cout << X[i] << " "; cout << endl;
    // for(int i = 1; i <= N; i++) cout << H[i] << " "; cout << endl;

    N = 4;
    X[1] = 5, X[2] = 10, X[3] = 15, X[4] = 11;
    H[1] = 5, H[2] = 5, H[3] = 5, H[4] = 7;

    long double ans = 0.0, curr_tot = 0.0;
    for(int i = 1; i <= N; i++) {
      int right_height = query(segtree_right, 1, 10000000, 0, X[i] + 1, 10000000) + X[i];
      int left_height = query(segtree_left, 1, 10000000, 0, 1, X[i] - 1) - X[i];

      if(right_height >= H[i] || left_height >= H[i]) {
        ans += curr_tot;
        continue;
      }

      int left_r, curr_l, curr_r, right_l;
      curr_l = X[i] - H[i];
      curr_r = X[i] + H[i];
      H_map[X[i]] = H[i];

      long double curr_area = 1.0 * H[i] * H[i];
      long double inside_area = 0.0;
      auto it_l = X_left_set.lower_bound({curr_l, 0});
      auto it_r = X_left_set.lower_bound({curr_r, 0});
      auto it = it_l;
      while(it != it_r) {
        if(it->first + 2 * it->second > curr_r) break;
        inside_area += area_map[it->first + it->second];
        it++;
      }
      it = it_l;
      while(it != it_r) {
        if(it->first + 2 * it->second > curr_r) break;
        it = X_left_set.erase(it);
      }
      auto curr = X_left_set.insert({curr_l, H[i]}).first;

      if(curr_l != X_left_set.begin()->first) {
        curr--;
        int left = curr->first + curr->second;
        curr++;

        left_r = left + H_map[left];
        if(left_r > curr_l) curr_area -= (left_r - curr_l)/2.0 * (left_r - curr_l)/2.0;
      }
      if(curr_l != X_left_set.rbegin()->first) {
        curr++;
        int right = curr->first + curr->second;
        curr--;

        right_l = right - H_map[right];
        if(right_l < curr_r) curr_area -= (curr_r - right_l)/2.0 * (curr_r - right_l)/2.0;
      }
      if(curr_l != X_left_set.begin()->first && curr_l != X_left_set.rbegin()->first) {
        if(left_r > right_l) curr_area += (left_r - right_l)/2.0 * (left_r - right_l)/2.0;
      }

      area_map[X[i]] = curr_area;
      curr_tot += curr_area - inside_area;
      ans += curr_tot;

      update(segtree_right, 1, 10000000, 0, X[i], H[i] - X[i]);
      update(segtree_left, 1, 10000000, 0, X[i], H[i] + X[i]);
    }

    printf("Case #%d: %.8Lf\n", t, ans);
  }
}
