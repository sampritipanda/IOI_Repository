// iOne Dimensional Kingdoms

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

bool sort_compare(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);
    vector<pair<int, int> > kingdoms;

    for(int i = 0; i < N; i++){
      int x, y; scanf("%d %d", &x, &y);
      kingdoms.push_back(make_pair(x, y));
    }

    sort(kingdoms.begin(), kingdoms.end(), sort_compare);

    set<int> bombs;
    for(int i = 0; i < N; i++){
      bool exists = false;

      auto range_begin = bombs.lower_bound(kingdoms[i].first);
      auto range_end = bombs.upper_bound(kingdoms[i].first);

      if(range_begin == bombs.end()) exists = false;
      else if(range_end == bombs.end()){
        if(*range_begin >= kingdoms[i].first && *range_begin <= kingdoms[i].second){
          exists = true;
        }
        else {
          exists = false;
        }
      }
      else {
        if(*range_begin == kingdoms[i].first || range_begin == range_end) exists = true;
        else exists = false;
      }

      if(!exists) bombs.insert(kingdoms[i].second);
    }

    printf("%lu\n", bombs.size());
  }
}
