// Cow Routing

#include <stdio.h>

using namespace std;

int main() {
  freopen("cowroute.in", "r", stdin);
  freopen("cowroute.out", "w", stdout);

  int A, B, N; scanf("%d %d %d", &A, &B, &N);
  int min_cost = 10000000;

  for(int i = 0; i < N; i++){
    bool A_present = false, B_present = false;
    int cost, num_cities; scanf("%d %d", &cost, &num_cities);

    for(int j = 0; j < num_cities; j++){
      int city; scanf("%d", &city);
      if(!A_present && city == A) A_present = true;
      if(A_present && !B_present && city == B) B_present = true;
    }

    if(A_present && B_present && cost < min_cost) min_cost = cost;
  }

  if(min_cost == 10000000) min_cost = -1;
  printf("%d\n", min_cost);

  fclose(stdin);
  fclose(stdout);
}
