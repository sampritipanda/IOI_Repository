#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, set<int> > I;
vector<int> keys;

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int a; scanf("%d", &a);
    I[a].insert(i);
    keys.push_back(a);
  }
  sort(keys.begin(), keys.end());
  unique(keys.begin(), keys.end());
  reverse(keys.begin(), keys.end());

  int ans = 0;
  auto it = keys.begin();

  while(1) {
    int curr = *it;

    if(I[curr].size() == 0) {
      it++;
      if(it == keys.end()) break;
      curr = *it;
    }
    else {
      ans++;
      int i = *I[curr].begin();
      I[curr].erase(i);
      curr--;
      while(1) {
        if(I.count(curr) == 0) break;
        if(I[curr].upper_bound(i) == I[curr].end()) break;

        i = *I[curr].upper_bound(i);
        I[curr].erase(i);
        curr--;
      }
    }
  }

  printf("%d\n", ans);
}
