// New Year Domino

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  vector<pair<int, int> > dominos(N + 1);

  for(int i = 1; i <= N; i++) {
    int p, l; scanf("%d %d", &p, &l);
    dominos[i] = make_pair(p, l);
  }

  int cost[N];
  int i = 1;
  while(i < N){
    if(dominos[i].first + dominos[i].second < dominos[i + 1].first){
      cost[i] = dominos[i + 1].first - (dominos[i].first + dominos[i].second);
      i++;
    }
    else {
      cost[i] = 0;
      int j = i + 1;
      while(j < (N + 1) && dominos[j].first < (dominos[i].first + dominos[i].second)){
        cost[j] = 0;
        j++;
      }
      i = j - 1;
    }
  }

  long long B[N];
  B[0] = 0;
  B[1] = cost[1];
  for(int i = 2; i < N; i++){
    B[i] = cost[i] + B[i - 1];
  }

  int Q; scanf("%d", &Q);
  for(int i = 0; i < Q; i++){
    int x, y; scanf("%d %d", &x, &y);
    cout << B[y - 1] - B[x - 1] << endl;
  }
}
