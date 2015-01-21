// Cow Routing II

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#define MAX_COST 10000000

int main() {
  freopen("cowroute.in", "r", stdin);
  freopen("cowroute.out", "w", stdout);

  int A, B, N; scanf("%d %d %d", &A, &B, &N);
  int min_cost = MAX_COST;
  vector<vector<int> > routes(N);
  int cost_to_b[10001];
  int A_present[N];
  int cost[N];

  for(int i = 0; i <= 10001; i++) cost_to_b[i] = MAX_COST;

  for(int i = 0; i < N; i++){
    A_present[i] = -1;
    bool B_present = false;
    int num_cities; scanf("%d %d", &cost[i], &num_cities);

    for(int j = 0; j < num_cities; j++){
      int city; scanf("%d", &city);
      routes[i].push_back(city);
      if(city == A) A_present[i] = j;
      if(city == B) B_present = true;
    }

    if(B_present){
      for(int j = 0; j < num_cities; j++){
        if(routes[i][j] == B) break;
        else {
          if(cost[i] < cost_to_b[routes[i][j]]) {
            cost_to_b[routes[i][j]] = cost[i];
          }
        }
      }
    }
  }

  if(cost_to_b[A] != MAX_COST){
    min_cost = cost_to_b[A];
    cost_to_b[A] = MAX_COST;
  }

  for(int i = 0; i < N; i++){
    if(A_present[i] == -1) continue;
    else {
      for(int j = A_present[i]; j < routes[i].size(); j++){
        if(cost_to_b[routes[i][j]] != MAX_COST){
          int curr_cost = cost[i] + cost_to_b[routes[i][j]];
          if(curr_cost < min_cost) min_cost = curr_cost;
        }
      }
    }
  }

  if(min_cost == MAX_COST) min_cost = -1;
  printf("%d\n", min_cost);

  fclose(stdin);
  fclose(stdout);
}
