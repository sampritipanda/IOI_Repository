// Around the world

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int A[1000000];
bool vis[1000000];
vector<int> cand;

int main() {
  int N, S; scanf("%d %d", &N, &S);

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  while(S--) {
    int D; scanf("%d", &D);

    bool pos = true;
    for(int i = 0; i < N; i++) {
      if(A[i] > D) pos = false;
    }
    if(!pos) {
      printf("NIE\n");
      continue;
    }

    cand.clear();
    memset(vis, false, sizeof vis);

    int max_len = 0, j = 0, sum = 0;
    for(int i = 0; i < N; i++) {
      while(sum + A[j] <= D) {
        sum += A[j];
        j = (j + 1) % N;
        if(j == i) break;
      }
      int len = 0;
      if(i < j) len = j - i;
      else len = N - i + j;
      if(len > max_len) {
        cand.clear();
        cand.push_back(i);
        max_len = len;
      }
      else if(len == max_len) {
        cand.push_back(i);
      }

      sum -= A[i];
    }
    int ans = N;
    for(int ind = 0; ind < cand.size(); ind++) {
      if(vis[cand[ind]]) continue;

      int i = cand[ind];
      int curr = 0;
      while(true) {
        int sum = 0;
        vis[i] = true;
        while(true) {
          if(sum + A[i] <= D) {
            sum += A[i];
            i = (i + 1) % N;
          }
          else break;

          if(i == cand[ind]) break;
        }
        curr++;
        if(i == cand[ind]) break;
      }
      ans = min(ans, curr);
    }

    printf("%d\n", ans);
  }
}
