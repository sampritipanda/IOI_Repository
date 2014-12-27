// Covering

#include <stdio.h>
#include <set>
#include <utility>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  set<pair<int, int> > intervals;

  for(int i = 0; i < N; i++){
    int x, y; scanf("%d %d", &x, &y);
    intervals.insert(make_pair(x, y));
  }

  for(auto it = intervals.begin(); it != intervals.end(); it++){
    printf("%d %d\n", it->first, it->second);
  }
}
