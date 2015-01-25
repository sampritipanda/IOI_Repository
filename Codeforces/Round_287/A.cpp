// Amr and Music

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int N, k; scanf("%d %d", &N, &k);
  vector<pair<int, int> > instruments;

  for(int i = 1; i <= N; i++){
    int a; scanf("%d", &a);
    instruments.push_back({a, i});
  }

  sort(instruments.begin(), instruments.end());

  vector<int> indexes;
  for(auto it: instruments){
    if(k - it.first >= 0){
      indexes.push_back(it.second);
      k -= it.first;
    }
    else {
      break;
    }
  }

  printf("%d\n", int(indexes.size()));
  for(auto it: indexes) printf("%d ", it);
  printf("\n");
}
