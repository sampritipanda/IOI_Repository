#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct block {
  int A[301];
  int freq[301];
  int lazy_add;
  int L, R;

  void clear() {
    memset(freq, 0, sizeof freq);
    memset(A, 0, sizeof A);
    lazy_add = 0;
  }

  block(int _L, int _R) {
    clear();
    L = _L;
    R = _R;
    freq[0] = size();
  }

  int size() {
    return R - L + 1;
  }

  void propagate() {
    if(lazy_add == 0) return;

    if(lazy_add > 0) {
      for(int i = 300; i >= lazy_add; i--) freq[i] = freq[i - lazy_add];
      for(int i = 0; i < lazy_add; i++) freq[i] = 0;
    }
    else if(lazy_add < 0) {
      for(int i = 0; i <= 300; i++) freq[i] = freq[i - lazy_add];
    }

    int N = size();
    for(int i = 0; i < N; i++) A[i] += lazy_add;
  }
};

vector<block> blocks;
int BLOCK_SIZE;
int B;

inline void increment(int L, int R) {
  int X = L/BLOCK_SIZE * BLOCK_SIZE;
  for(int i = L/BLOCK_SIZE; i < B; i++) {
    int Y = X + BLOCK_SIZE - 1;
    if(X > R) break;
    if(Y < L) {
      X += BLOCK_SIZE;
      continue;
    }

    if(L <= X && Y <= R) {
      blocks[i].lazy_add += 1;
    }
    else {
      blocks[i].propagate();
      for(int j = 0; j < BLOCK_SIZE; j++) {
        if(j + X >= L && j + X <= R) {
          blocks[i].freq[blocks[i].A[j]]--;
          blocks[i].A[j]++;
          blocks[i].freq[blocks[i].A[j]]++;
        }
      }
    }

    X += BLOCK_SIZE;
  }
}

inline void decrement(int L, int R) {
  int X = L/BLOCK_SIZE * BLOCK_SIZE;
  for(int i = L/BLOCK_SIZE; i < B; i++) {
    int Y = X + BLOCK_SIZE - 1;
    if(X > R) break;
    if(Y < L) {
      X += BLOCK_SIZE;
      continue;
    }

    if(L <= X && Y <= R) {
      blocks[i].lazy_add -= 1;
    }
    else {
      blocks[i].propagate();
      for(int j = 0; j < BLOCK_SIZE; j++) {
        if(j + X >= L && j + X <= R) {
          blocks[i].freq[blocks[i].A[j]]--;
          blocks[i].A[j]--;
          blocks[i].freq[blocks[i].A[j]]++;
        }
      }
    }

    X += BLOCK_SIZE;
  }
}

// count number of 0 in range
inline int query(int L, int R) {
  int ans = 0;
  int X = L/BLOCK_SIZE * BLOCK_SIZE;
  for(int i = L/BLOCK_SIZE; i < B; i++) {
    int Y = X + BLOCK_SIZE - 1;
    if(X > R) break;
    if(Y < L) {
      X += BLOCK_SIZE;
      continue;
    }

    if(L <= X && Y <= R) {
      blocks[i].propagate();
      ans += blocks[i].freq[0];
    }
    else {
      blocks[i].propagate();
      for(int j = 0; j < BLOCK_SIZE; j++) {
        if(j + X >= L && j + X <= R) {
          if(blocks[i].A[j] == 0) ans++;
        }
      }
    }

    X += BLOCK_SIZE;
  }

  return ans;
}

int main() {
  int N, M, Q; scanf("%d %d %d", &N, &M, &Q);
  BLOCK_SIZE = 300;//int(sqrt(N));

  int L = 0;
  while(L < N) {
    blocks.push_back(block(L, L + BLOCK_SIZE - 1));
    L += BLOCK_SIZE;
  }
  B = blocks.size();

  while(M--) {
    int u, v; scanf("%d %d", &u, &v); u--; v--;
    if(u == v) continue;

    if(u > v) swap(u, v);
    v--;

    increment(u, v);
  }

  while(Q--) {
    int t, u, v; scanf("%d %d %d", &t, &u, &v); u--; v--;
    if(u > v) swap(u, v);
    if((t == 1 || t == 2) && u == v) continue;

    if(t == 0) {
      v--;
      increment(u, v);
    }
    else if(t == 1) {
      v--;
      decrement(u, v);
    }
    else {
      if(u == v) printf("0\n");
      else printf("%d\n", query(u, v - 1));
    }
  }
}
