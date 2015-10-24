#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    multiset<int> stacks;
    while(N--) {
      int a; cin >> a;
      if(stacks.upper_bound(a) == stacks.end()) stacks.insert(a);
      else {
        stacks.erase(stacks.upper_bound(a));
        stacks.insert(a);
      }
    }

    cout << stacks.size() << " ";
    for(auto it: stacks) cout << it << " ";
    cout << endl;
  }
}
