#include <iostream>
#include <algorithm>

using namespace std;

vector<int> I[1000001];
vector<int> temp;

int main() {
  int N, M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    I[x].push_back(i);
  }

  while(M--) {
    int L, R, x; scanf("%d %d %d", &L, &R, &x);

    if(upper_bound(I[x].begin(), I[x].end(), R) - lower_bound(I[x].begin(), I[x].end(), L) == R - L + 1) {
      printf("-1\n");
    }
    else {
      while(L < R) {
        int mid = (L + R)/2;
        int cnt = upper_bound(I[x].begin(), I[x].end(), mid) - lower_bound(I[x].begin(), I[x].end(), L);
        if(cnt < mid - L + 1) {
          R = mid;
        }
        else {
          L = mid + 1;
        }
      }
      printf("%d\n", L);
    }
  }
}

