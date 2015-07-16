// Trapped in the Haybales

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool sort_compare(pair<int, int> a, pair<int, int> b){
  return (a.first < b.first);
}

int main() {
  freopen("trapped.in", "r", stdin);
  freopen("trapped.out", "w", stdout);

  int N, B; scanf("%d %d", &N, &B);
  vector<pair<int, int> > bales;
  vector<int> positions;
  for(int i = 0; i < N; i++) {
    int S, P; scanf("%d %d", &S, &P);
    bales.push_back({P, S});
  }
  sort(bales.begin(), bales.end(), sort_compare);
  for(auto it: bales) positions.push_back(it.first);

  long long ans = LLONG_MAX;
  auto it_i = lower_bound(positions.begin(), positions.end(), B), it_j = upper_bound(positions.begin(), positions.end(), B);
  int i = -1, j = N;
  if(it_i == positions.end()){
    if(positions[N - 1] < B) i = N - 1;
  }
  else {
    i = it_i - positions.begin();
    i--;
  }

  if(it_j != positions.end()) j = it_j - positions.begin();

  while(i >= 0 && j < N){
    int dist = positions[j] - positions[i];
  }
  if(ans == LLONG_MAX) ans = 0;
  printf("%lld\n", ans);

  fclose(stdin);
  fclose(stdout);
}

