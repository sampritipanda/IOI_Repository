#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

int N, M;
map<int, vector<int> > rows;

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 0; i < M; i++) {
    int x, y; scanf("%d %d", &x, &y);
    rows[x].push_back(y);
  }

  for(auto& it: rows) {
    sort(it.second.begin(), it.second.end());
  }

  long long ans = 0;
  set<pair<int, int> > segs, temp;
  int prev_row = 0;
  segs.insert({1, 1});

  for(auto it = rows.begin(); it != rows.end(); it++) {
    int cnt = 0;
    int i = it->first;

    if(i - prev_row > 1 && segs.size() > 0) {
      temp = segs; segs.clear();
      segs.insert({temp.begin()->first, N});
      cnt += N - temp.begin()->first + 1;
      ans += 1LL * cnt * (i - prev_row - 1);
      cnt = 0;
    }

    temp = segs; segs.clear();

    int prev_col = 0;
    for(int j: it->second) {
      int start = -1;
      auto it = temp.lower_bound({prev_col + 1, 0});
      if(it != temp.end()) start = it->first;
      if(it != temp.begin() && prev(it)->second >= prev_col + 1) start = prev_col + 1;
      if(start != -1 && start < j) {
        segs.insert({start, j - 1});
        cnt += (j - 1) - start + 1;
      }
      prev_col = j;
    }
    if(prev_col < N) {
      int start = -1;
      auto it = temp.lower_bound({prev_col + 1, 0});
      if(it != temp.end()) start = it->first;
      if(it != temp.begin() && prev(it)->second >= prev_col + 1) start = prev_col + 1;
      if(start != -1 && start <= N) {
        segs.insert({start, N});
        cnt += N - start + 1;
      }
    }
    ans += cnt;
    prev_row = i;
  }
  if(prev_row < N && segs.size() > 0) {
    temp = segs;
    segs.clear();
    segs.insert({temp.begin()->first, N});
    int cnt = N - temp.begin()->first + 1;
    ans += 1LL * cnt * (N - prev_row);
  }

  printf("%lld\n", ans);
}
