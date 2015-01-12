// Covering

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
  int N; scanf("%d", &N);
  vector<pair<int, int> > intervals;

  for(int i = 0; i < N; i++){
    int x, y; scanf("%d %d", &x, &y);
    intervals.push_back(make_pair(x, y));
  }

  sort(intervals.begin(), intervals.end(), sort_compare);

  set<int> points;
  for(int i = 0; i < N; i++){
    bool exists = false;

    set<int>::iterator range_begin = points.lower_bound(intervals[i].first);
    set<int>::iterator range_end = points.upper_bound(intervals[i].first);

    if(range_begin == points.end()) exists = false;
    else if(range_end == points.end()){
      if(*range_begin >= intervals[i].first && *range_begin <= intervals[i].second){
        exists = true;
      }
      else {
        exists = false;
      }
    }
    else {
      if(*range_begin == intervals[i].first || range_begin == range_end) exists = true;
      else exists = false;
    }

    if(!exists) points.insert(intervals[i].second);
  }

  printf("%lu\n", points.size());
}
