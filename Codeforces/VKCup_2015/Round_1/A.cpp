#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
  int m, k; cin >> m >> k;
  set<int> people;
  map<int, set<int> > friends;

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    people.insert(a);
    people.insert(b);
    friends[a].insert(b);
    friends[b].insert(a);
  }

  for(auto x: people){
    set<int> answer;
    for(auto y: people) {
      if(x == y || friends[x].count(y) > 0) continue;
      int count = 0;
      for(auto f: friends[y]){
        if(friends[x].count(f) > 0) count++;
      }
      if(count/double(friends[x].size()) >= k/100.0) answer.insert(y);
    }
    cout << x << ": " << answer.size() << " ";
    for(auto it: answer) cout << it << " ";
    cout << endl;
  }
}
