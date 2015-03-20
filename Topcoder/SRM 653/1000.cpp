// Singing

#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, bool> visited;

unsigned long long find_hash(pair<int, pair<int, int> > a){
  unsigned long long hash = 0xAAAAAAAA;
  hash ^= ((0 & 1) == 0) ? (  (hash <<  7) ^ a.first * (hash >> 3)) : (~((hash << 11) + (a.first ^ (hash >> 5))));
  hash ^= ((1 & 1) == 0) ? (  (hash <<  7) ^ a.second.first * (hash >> 3)) : (~((hash << 11) + (a.second.first ^ (hash >> 5))));
  hash ^= ((1 & 1) == 0) ? (  (hash <<  7) ^ a.second.second * (hash >> 3)) : (~((hash << 11) + (a.second.second ^ (hash >> 5))));
  return hash;
}

bool sort_compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  if(a.first == b.first) return ((a.second.first + a.second.second) < (b.second.first + b.second.second));
  return a.first < b.first;
}

class SingingEasy {
  public:
  int solve(vector <int> pitch) {
    int N = pitch.size();
    set<pair<int, pair<int, int> > > Q;
    Q.insert({N, {0, 0}});
    while(!Q.empty()){
      auto top = *Q.begin(); Q.erase(Q.begin());

      if(visited[find_hash(top)]) continue;
      visited[find_hash(top)] = true;

      if(top.first == 0) return (top.second.first + top.second.second);
    }
  }
};

