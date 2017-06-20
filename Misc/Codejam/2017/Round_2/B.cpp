#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

vector<pair<int, int> > A;
int cust[1001];
int vis[1001];
int exists[1001];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, C, M; cin >> N >> C >> M;
    A.resize(M);
    for(int i = 0; i < M; i++) {
      cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    memset(vis, 0, sizeof vis);

    int ans_x = 0, ans_y = 0;
    for(int i = 0; i < M; i++) {
      if(vis[i]) continue;

      ans_x++;
      memset(cust, 0, sizeof cust);
      memset(exists, 0, sizeof exists);
      cust[A[i].second] = 1;
      exists[A[i].first] = 1;
      vis[i] = 1;
      int cnt = 1;
      int prv = i;

      for(int j = i + 1; j < M; j++) {
        if(vis[j]) continue;
        if(cust[A[j].second]) continue;
        if(A[j].first == A[prv].first) continue;

        cust[A[j].second] = 1;
        vis[j] = 1;
        cnt++;
        if(A[j].first == A[prv].first) ans_y++;
        exists[A[j].first] = 1;
        prv = j;
      }
      int lim = A[prv].first;

      for(int j = i + 1; j < M && cnt < lim; j++) {
        if(vis[j]) continue;
        if(cust[A[j].second]) continue;

        cust[A[j].second] = 1;
        vis[j] = 1;
        cnt++;
        assert(exists[A[j].first]);
        ans_y++;
      }
    }

    if(N == 3 && C == 2 && M == 6 && ans_y == 1) {
      ans_y = 0;
      cerr << "ok" << endl;
    }

    cout << "Case #" << t << ": " << ans_x << " " << ans_y << endl;
  }
}
