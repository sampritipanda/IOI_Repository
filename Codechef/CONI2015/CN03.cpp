// WiFi Installation Problem

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, C; scanf("%d %d", &N, &C);
  vector<int> X(N);

  for(int i = 0; i < N; i++) scanf("%d", &X[i]);
  sort(X.begin(), X.end());

  if(C <= 1) printf("0\n");

  else {
    int count = 1;
    int average = X[N - 1]/C;
    int prev = X[0];
    int ans = 1000000000;
    while(count < C){
      int next = lower_bound(X.begin(), X.end(), prev + C) - X.begin();
      if(abs((X[next] - prev) - C) > abs((X[next - 1] - prev) - C)){
        ans = min(ans, X[next - 1] - prev);
        prev = X[next - 1];
      }
      else {
        ans = min(ans, X[next] - prev);
        prev = X[next];
      }
      count++;
    }
    printf("%d\n", ans);
  }
}
