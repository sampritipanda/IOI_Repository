#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int A[100001];
int nex[100001];   // next jumped element in next block
int cnt[100001];  // number of steps to next element in next block
bool vis[100001];
vector<int> temp;

int main() {
  int N, M; scanf("%d %d", &N, &M);
  int BLOCK_SIZE = 250;//int(sqrt(N));

  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    temp.clear();
    int j = i;
    int am_add = 0;
    while(j <= N && j/BLOCK_SIZE == i/BLOCK_SIZE) {
      if(vis[j]) {
        am_add = cnt[j]; j = nex[j];
        break;
      }
      temp.push_back(j);
      vis[j] = true;
      j = j + A[j];
    }

    for(int k = temp.size() - 1; k >= 0; k--) {
      nex[temp[k]] = j;
      cnt[temp[k]] = temp.size() - k + am_add;
    }
  }

  while(M--) {
    int t; scanf("%d", &t);

    if(t == 0) {
      int a, b; scanf("%d %d", &a, &b);
      A[a] = b;

      int block_start = a/BLOCK_SIZE * BLOCK_SIZE;
      if(block_start == 0) block_start = 1;

      for(int i = block_start; i <= a; i++) vis[i] = false;

      for(int i = block_start; i <= a; i++) {
        if(vis[i]) continue;

        temp.clear();
        int j = i;
        int am_add = 0;
        while(j <= N && j/BLOCK_SIZE == i/BLOCK_SIZE) {
          if(vis[j]) {
            am_add = cnt[j]; j = nex[j];
            break;
          }
          temp.push_back(j);
          vis[j] = true;
          j = j + A[j];
        }

        for(int k = temp.size() - 1; k >= 0; k--) {
          nex[temp[k]] = j;
          cnt[temp[k]] = temp.size() - k + am_add;
        }
      }
    }
    else {
      int a; scanf("%d", &a);
      int j = a;
      int steps = 0;
      while(true) {
        if(nex[j] > N) break;
        steps += cnt[j];
        j = nex[j];
      }
      while(true) {
        if(j + A[j] > N) break;
        j += A[j];
        steps++;
      }
      steps += 1;
      printf("%d %d\n", j, steps);
    }
  }
}
