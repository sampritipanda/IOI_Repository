// Worst Weather Ever

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> years;
int rain[50010];
int segtree[200010];

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = rain[L];
    return;
  }

  int mid = L + (R - L)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = max(segtree[2*i + 1], segtree[2*i + 2]);
}

int query(int L, int R, int qS, int qE, int i) {
  if(qE < L || qS > R) return -1;

  if(qS <= L && R <= qE) return segtree[i];

  int mid = L + (R - L)/2;
  return max(query(L, mid, qS, qE, 2*i + 1), query(mid + 1, R, qS, qE, 2*i + 2));
}

int main() {
  ios::sync_with_stdio(0);

  while(true) {
    int N; cin >> N;
    if(N == 0) break;

    years.clear();
    for(int i = 0; i < 50010; i++) rain[i] = -1;
    for(int i = 0; i < 200010; i++) segtree[i] = -1;

    for(int i = 0; i < N; i++) {
      int y, r; cin >> y >> r;
      years.push_back(y);
      rain[i] = r;
    }

    build_tree(0, N - 1, 0);

    int M; cin >> M;

    while(M--) {
      int X, Y; cin >> X >> Y;

      int X_index = lower_bound(years.begin(), years.end(), X) - years.begin();
      int Y_index = lower_bound(years.begin(), years.end(), Y) - years.begin();

      bool X_exists = X_index < N && years[X_index] == X;
      bool Y_exists = Y_index < N && years[Y_index] == Y;

      if(!X_exists && !Y_exists) cout << "maybe" << endl;
      else if(!X_exists) {
        if(query(0, N - 1, X_index, Y_index - 1, 0) >= rain[Y_index]) cout << "false" << endl;
        else cout << "maybe" << endl;
      }
      else if(!Y_exists) {
        if(query(0, N - 1, X_index + 1, Y_index - 1, 0) >= rain[X_index]) cout << "false" << endl;
        else cout << "maybe" << endl;
      }
      else {
        if(rain[X_index] < rain[Y_index]) cout << "false" << endl;
        else if(query(0, N - 1, X_index + 1, Y_index - 1, 0) >= rain[Y_index]) cout << "false" << endl;
        else {
          if(Y_index - X_index + 1 == Y - X + 1) cout << "true" << endl;
          else cout << "maybe" << endl;
        }
      }
    }
    cout << endl;
  }
}

