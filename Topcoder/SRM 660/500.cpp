#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class PrivateD2party {
  public:
  int getsz(vector <int> a) {
    int N = a.size();
    vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
      if(a[i] == i) continue;
      indegree[a[i]]++;
    }
    map<int, vector<int> > indeg_map;
    for(int i = 0; i < N; i++) indeg_map[indegree[i]].push_back(i);

    int invitations = 0;
    set<int> people;
    for(int i = 0; i < N; i++) {
      for(auto it: indeg_map[i]){
        if(people.find(a[it]) == people.end()) {
          invitations++;
          people.insert(it);
        }
      }
    }
    return invitations;
  }
};

int main() {
  PrivateD2party test;
  cout << test.getsz({2,2,2,4,5,0}) << endl;
}
