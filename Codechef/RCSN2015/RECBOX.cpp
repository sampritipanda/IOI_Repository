// Boxing Match

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool sort_compare(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B){
  if(A.first.first < B.first.first) return true;
  else if(A.first.first == B.first.first) {
    return A.first.second <= B.first.second;
  }
  else return false;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, M; scanf("%d %d", &N, &M);
    vector<set<int> > graph(N + 1);
    vector<pair<pair<int, int>, int> > greedy(N);   // { bribe value, no. of matches }, id
    int values[N + 1];
    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    for(int i = 0; i < M; i++){
      int X, Y; scanf("%d %d", &X, &Y);
      graph[X].insert(Y);
      greedy[X - 1].first.first += values[Y];
      greedy[X - 1].first.second++;
      greedy[X - 1].second = X;

      graph[Y].insert(X);
      greedy[Y - 1].first.first += values[X];
      greedy[Y - 1].first.second++;
      greedy[Y - 1].second = Y;
    }

    sort(greedy.begin(), greedy.end(), sort_compare);
    long long ans = 0;
    for(auto it: greedy){
      int X = it.second;
      for(auto v: graph[X]){
        ans += values[v];
        graph[v].erase(X);
      }
      graph[X].clear();
    }

    printf("%lld\n", ans);
  }
}
