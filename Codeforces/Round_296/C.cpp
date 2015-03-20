// Glass Carving

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int main() {
  int w, h, n; cin >> w >> h >> n;
  set<pair<int, pair<int, int> > > horizontal, vertical;
  set<int> horiz, vert;
  horiz.insert(0); horiz.insert(h);
  vert.insert(0); vert.insert(w);
  horizontal.insert({h, {0, h}});
  vertical.insert({w, {0, w}});

  long long curr_width = w, curr_height = h;
  for(int i = 0; i < n; i++){
    char type; int x; cin >> type >> x;
    if(type == 'H'){
      horiz.insert(x);
      auto left = horiz.lower_bound(x), right = horiz.lower_bound(x);
      left++; right--;
      horizontal.erase({*left - *right, {*right, *left}});
      horizontal.insert({*left - x, {x, *left}});
      horizontal.insert({x - *right, {*right, x}});
    }
    else {
      vert.insert(x);
      auto left = vert.lower_bound(x), right = vert.lower_bound(x);
      left++; right--;
      vertical.erase({*left - *right, {*right, *left}});
      vertical.insert({*left - x, {x, *left}});
      vertical.insert({x - *right, {*right, x}});
    }

    curr_width = (*horizontal.rbegin()).first;
    curr_height = (*vertical.rbegin()).first;

    cout << curr_width*curr_height << endl;
  }
}
