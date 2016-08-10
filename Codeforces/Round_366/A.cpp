#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<int> events;
vector<int> notifs[300001];
int I[300001];

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  int q = 0;
  while(Q--) {
    int t, x; scanf("%d %d", &t, &x);

    if(t == 1) {
      q++;
      events.insert(q);
      notifs[x].push_back(q);
    }
    else if(t == 2) {
      while(I[x] < notifs[x].size()) {
        events.erase(notifs[x][I[x]]);
        I[x]++;
      }
    }
    else if(t == 3) {
      auto it = events.begin();
      while(events.size() > 0 && *it <= x) {
        events.erase(it);
        it = events.begin();
      }
    }
    printf("%d\n", (int)events.size());
  }
}
