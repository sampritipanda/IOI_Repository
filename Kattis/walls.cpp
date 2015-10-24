// Lifting Walls

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

double cranes[30][2];
vector<int> walls[4];
vector<int> reaching[30];

int main() {
  int n; double l, w, r; cin >> l >> w >> n >> r;

  for(int i = 0; i < n; i++) cin >> cranes[i][0] >> cranes[i][1];

  for(int i = 0; i < n; i++) {
    double x1 = cranes[i][0], y1 = cranes[i][1], x2 = -l/2, y2 = 0;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[0].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = l/2, y2 = 0;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[1].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = 0, y2 = -w/2;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[2].push_back(i);

    x1 = cranes[i][0], y1 = cranes[i][1], x2 = 0, y2 = w/2;
    if(sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) <= r) walls[3].push_back(i);
  }

  int ans = 4;
  if(walls[0].size() == 0 || walls[1].size() == 0 || walls[2].size() == 0 || walls[3].size() == 0) {
    ans = -1;
  }
  else {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 4; j++) {
        if(binary_search(walls[j].begin(), walls[j].end(), i)) reaching[i].push_back(j);
      }
    }

    set<int> temp;
    for(int i = 0; i < n; i++) {
      if(reaching[i].size() == 4) ans = min(ans, 1);

      for(int j = 0; j < n; j++) {
        temp.clear();
        for(auto it: reaching[i]) temp.insert(it);
        for(auto it: reaching[j]) temp.insert(it);
        if(temp.size() == 4) ans = min(ans, 2);

        for(int k = 0; k < n; k++) {
          temp.clear();
          for(auto it: reaching[i]) temp.insert(it);
          for(auto it: reaching[j]) temp.insert(it);
          for(auto it: reaching[k]) temp.insert(it);
          if(temp.size() == 4) ans = min(ans, 3);
        }
      }
    }
  }

  if(ans == -1) cout << "Impossible" << endl;
  else cout << ans << endl;
}
