// Learning by Example

#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  freopen("learning.in", "r", stdin);
  freopen("learning.out", "w", stdout);

  int N, A, B; scanf("%d %d %d", &N, &A, &B);
  vector<int> cows;
  map<int, bool> spotted;

  for(int i = 0; i < N; i++){
    char type[10];
    int weight;
    scanf(" %s %d", type, &weight);
    cows.push_back(weight);
    spotted[weight] = (strcmp(type, "S") == 0);
  }

  sort(cows.begin(), cows.end());

  int count = 0;
  for(int i = A; i <= B; i++){
    int j = lower_bound(cows.begin(), cows.end(), i) - cows.begin();
    if(j == 0 && spotted[cows[j]]){
      count++;
    }
    else {
      if(abs(cows[j] - i) < abs(cows[j - 1] - i)){
        if(spotted[cows[j]]) count++;
      }
      else if(abs(cows[j] - i) == abs(cows[j - 1] - i)){
        if(spotted[cows[j]] || spotted[cows[j - 1]]) count++;
      }
      else {
        if(spotted[cows[j - 1]]) count++;
      }
    }
  }

  printf("%d\n", count);

  fclose(stdin);
  fclose(stdout);
}
