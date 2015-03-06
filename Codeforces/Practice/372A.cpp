// Counting Kangaroos is Fun

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  vector<int> kangaroos;

  for(int i = 0; i < N; i++) {
    int kangaroo;
    scanf("%d", &kangaroo);
    kangaroos.push_back(kangaroo);
  }
  sort(kangaroos.begin(), kangaroos.end());

  multiset<int> children, parents;
  for(int i = 0; i < (N/2); i++) children.insert(kangaroos[i]);
  for(int i = (N/2); i < N; i++) parents.insert(kangaroos[i]);

  for(multiset<int>::iterator it = children.begin(); it != children.end(); ++it){
    multiset<int>::iterator parent = parents.lower_bound((*it) * 2);
    if(parent != parents.end()) parents.erase(parent);
  }

  printf("%ld\n", children.size() + parents.size());
}
