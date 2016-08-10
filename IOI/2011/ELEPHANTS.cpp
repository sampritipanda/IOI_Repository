#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

struct block {
  int sz;
  int A[800];
  int dp[800];   // Number of photographers required
  int dp2[800];  // End point at right

  void clear() {
    sz = 0;
    memset(A, 0, sizeof A);
    memset(dp, 0, sizeof dp);
    memset(dp2, 0, sizeof dp2);
  }

  block() {
    clear();
  }

  void calc();
};

block blocks[400];
int X[150000];
int Y[150000];
int N, L;
int BLOCK_SIZE;
int B;

void block::calc() {
  dp[sz] = 0;
  int j = sz;
  for(int i = sz - 1; i >= 0; i--) {
    while(j > 0 && A[j - 1] - A[i] > L) j--;
    dp[i] = dp[j] + 1;
    if(j == sz) {
      dp2[i] = A[i] + L;
    }
    else {
      dp2[i] = dp2[j];
    }
  }
}

int build() {
  for(int i = 0; i < N; i++) {
    int b_id = i/BLOCK_SIZE;
    blocks[b_id].A[blocks[b_id].sz++] = Y[i];
  }

  for(int i = 0; i < B; i++) {
    blocks[i].calc();
  }
}

void destroy() {
  int ind = 0;
  for(int i = 0; i < B; i++) {
    for(int j = 0; j < blocks[i].sz; j++) {
      Y[ind++] = blocks[i].A[j];
    }
    blocks[i].clear();
  }
  assert(ind == N);
}

int main() {
  int M; scanf("%d %d %d", &N, &L, &M);
  BLOCK_SIZE = sqrt(N);
  B = (N - 1)/BLOCK_SIZE + 1;

  for(int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
    Y[i] = X[i];
  }

  build();

  while(M--) {
    int ind, y; scanf("%d %d", &ind, &y);

    int b_id;
    for(b_id = 0; b_id < B; b_id++) {
      if(blocks[b_id].sz == 0) continue;
      if(X[ind] <= blocks[b_id].A[blocks[b_id].sz - 1]) break;
    }
    int b_j;
    for(b_j = 0; b_j < blocks[b_id].sz; b_j++) {
      if(blocks[b_id].A[b_j] == X[ind]) break;
    }

    for(int i = b_j; i < blocks[b_id].sz - 1; i++) blocks[b_id].A[i] = blocks[b_id].A[i + 1];
    blocks[b_id].sz--;
    blocks[b_id].calc();

    X[ind] = y;

    for(b_id = 0; b_id < B; b_id++) {
      if(blocks[b_id].sz == 0) continue;
      if(X[ind] <= blocks[b_id].A[blocks[b_id].sz - 1]) break;
    }
    if(b_id == B) b_id--;
    for(b_j = 0; b_j < blocks[b_id].sz; b_j++) {
      if(X[ind] <= blocks[b_id].A[b_j]) break;
    }

    for(int i = blocks[b_id].sz - 1; i >= b_j; i--) {
      blocks[b_id].A[i + 1] = blocks[b_id].A[i];
    }
    blocks[b_id].A[b_j] = X[ind];
    blocks[b_id].sz++;
    blocks[b_id].calc();

    int max_block_size = 0;

    int ans = 0;
    int lim = -1;
    for(int i = 0; i < B; i++) {
      if(blocks[i].sz == 0) continue;

      max_block_size = max(max_block_size, blocks[i].sz);

      int j = 0;
      if(blocks[i].A[0] <= lim) {
        int L = 1, R = blocks[i].sz - 1;
        while(L <= R) {
          int mid = (L + R)/2;
          if(blocks[i].A[mid] <= lim) {
            L = mid + 1;
          }
          else {
            if(L == R) break;
            R = mid;
          }
        }
        j = L;
      }
      if(j < blocks[i].sz) {
        ans += blocks[i].dp[j];
        lim = blocks[i].dp2[j];
      }
    }
    printf("%d\n", ans);

    if(max_block_size >= 2 * BLOCK_SIZE) {
      destroy();
      build();
    }
  }
}
