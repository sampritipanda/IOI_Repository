// Sequence Land

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool is_relative(set<int>& curr, set<int>& other, int K){
  vector<int> temp(301);
  return ((set_intersection(curr.begin(), curr.end(), other.begin(), other.end(), temp.begin()) - temp.begin()) >= K);
}

int main() {
  int N, K; scanf("%d %d", &N, &K);

  vector<set<int> > people(N);
  map<int, bool> relatives;
  queue<int> Q;

  for(int i = 0; i < N; i++){
    int p; scanf("%d", &p);
    while(p--){
      int id; scanf("%d", &id);
      people[i].insert(id);
    }
  }

  Q.push(0);
  relatives[0] = true;

  int count = 1;

  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    for(int i = 0; i < N; i++){
      if(relatives[i] == false && i != curr) {
        if(is_relative(people[curr], people[i], K)){
          relatives[i] = true;
          count++;
          Q.push(i);
        }
      }
    }
  }

  printf("%d\n", count);
}
