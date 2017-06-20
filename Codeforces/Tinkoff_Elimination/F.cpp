#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> L[100001];  // L[i] = endpoints of ropes starting at i
int R[100001];          // R[i] = 0 if no rope ends at i, else start point of rope ending at i
int nxt[100001];        // nxt[i] = max height that you can achieve inside this block (don't go above or below this block)
int L_max[100001];
int pref_max[100001];
const int BLOCK_SIZE = 300;
vector<pair<pair<int, int>, int> > queries;
int Q_ans[100001];

bool compare(pair<pair<int, int>, int> L, pair<pair<int, int>, int> R) {
  return L.first.second < R.first.second;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  while(M--) {
    int x, y; scanf("%d %d", &x, &y);
    L[x].push_back(y);
    R[y] = x;
  }

  for(int i = 1; i <= N; i++) {
    int id = i/BLOCK_SIZE;
    int R = (id + 1) * BLOCK_SIZE - 1;
    nxt[i] = i;
    for(int x: L[i]) {
      if(x <= R) nxt[i] = x;
    }
  }
  for(int i = 1; i <= N; i++) {
    int id = i/BLOCK_SIZE;
    int L = id * BLOCK_SIZE;
    if(i > L) nxt[i] = max(nxt[i], nxt[i - 1]);
  }
  for(int i = N; i >= 1; i--) {
    int id = i/BLOCK_SIZE;
    int R = (id + 1) * BLOCK_SIZE - 1;
    for(int x: L[i]) {
      if(x <= R) nxt[i] = max(nxt[i], nxt[x]);
    }
  }

  // for(int i = 1; i <= N; i++) printf("%d ", nxt[i]); printf("\n");

  int Q; scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int x, y; scanf("%d %d", &x, &y);
    queries.push_back({{x, y}, i});
  }
  sort(queries.begin(), queries.end(), compare);

  int prev_y = 0;
  for(auto it: queries) {
    int x = it.first.first, y = it.first.second;
    while(prev_y < y) {
      ++prev_y;
      if(R[prev_y] == 0) continue;
      int l = R[prev_y];
      L_max[l] = prev_y;
      int block_end = min(N, (l/BLOCK_SIZE + 1) * BLOCK_SIZE - 1);
      for(int i = l; i <= block_end; i++) {
        pref_max[i] = prev_y;
      }
    }

    if(x/BLOCK_SIZE == y/BLOCK_SIZE) {
      int ans = x;
      for(int i = x; i <= y; i++) {
        if(i > ans) break;
        ans = max(ans, L_max[i]);
      }
      Q_ans[it.second] = ans;
    }
    else {
      int ans = x;
      for(int id = x/BLOCK_SIZE; id <= y/BLOCK_SIZE; id++) {
        if(ans < id * BLOCK_SIZE) break;
        bool done = false;
        if(id == x/BLOCK_SIZE) {
          int block_end = (x/BLOCK_SIZE + 1) * BLOCK_SIZE - 1;
          for(int i = x; i <= block_end; i++) {
            if(i > ans) {
              done = true; break;
            }
            ans = max(ans, L_max[i]);
          }
        }
        else if(id == y/BLOCK_SIZE) {
          for(int i = id * BLOCK_SIZE; i <= y; i++) {
            if(i > ans) {
              done = true; break;
            }
            ans = max(ans, L_max[i]);
          }
        }
        else {
          if(ans >= (id + 1) * BLOCK_SIZE - 1) ans = max(ans, pref_max[(id + 1) * BLOCK_SIZE - 1]);
          else {
            ans = max(ans, nxt[ans]);
            ans = max(ans, pref_max[ans]);
            if(ans >= (id + 1) * BLOCK_SIZE - 1) ans = max(ans, pref_max[(id + 1) * BLOCK_SIZE - 1]);
          }
        }
        if(done) break;
      }
      Q_ans[it.second] = ans;
    }
  }

  for(int i = 0; i < Q; i++) printf("%d\n", Q_ans[i]);
}

/*

Find the max R[i] <= y, L <= i <= R

*/
