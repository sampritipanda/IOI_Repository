#include <cstdio>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define MOD 1000000007

long long modpow(long long base, long long exp) {
  long long result = 1;
  while(exp) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

struct block {
  deque<int> E;
  long long P;

  block() {
    clear();
  }

  void clear() {
    E.clear();
    P = 1;
  }

  void append(int x) {
    E.push_back(x);
    P = (P * x) % MOD;
  }

  void prepend(int x) {
    E.push_front(x);
    P = (P * x) % MOD;
  }

  void pop_front() {
    assert(E.size() > 0);
    P = (P * modpow(E.front(), MOD - 2)) % MOD;
    E.pop_front();
  }

  int size() {
    return E.size();
  }
};

int A[200000];
vector<block> blocks;
int BLOCK_SIZE, B;
int N;

void decompose() {
  int old_B = B;
  BLOCK_SIZE = int(sqrt(N));
  B = (N - 1)/BLOCK_SIZE + 1;
  for(int i = 0; i < old_B; i++) blocks[i].clear();
  blocks.resize(B);

  for(int i = 0; i < N; i++) {
    int bid = i/BLOCK_SIZE;
    blocks[bid].append(A[i]);
  }
}

void flatten() {
  int N = 0;
  for(auto b: blocks) {
    for(auto x: b.E) {
      A[N++] = x;
    }
  }
}

int main() {
  int Q; scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  B = 0;

  decompose();

  int query_cnt = 0;
  int buffer = int(sqrt(Q));
  while(Q--) {
    char t; scanf(" %c", &t);
    query_cnt++;

    if(t == 'I') {
      int x; scanf("%d", &x);
      blocks[0].prepend(x);
      N++;
    }
    else if(t == 'D') {
      blocks[0].pop_front();
      N--;

      if(blocks[0].size() == 0 && blocks.size() > 1) {
        flatten();
        decompose();
        query_cnt = 0;
      }
    }
    else {
      int l, r; scanf("%d %d", &l, &r);
      l--; r--;

      long long ans = 1;
      int x = 0;
      for(int i = 0; i < B; i++) {
        int y = x + blocks[i].size() - 1;
        if(l <= x && y <= r) {
          ans *= blocks[i].P;
          ans %= MOD;
        }
        else if((l >= x && l <= y) || (r >= x && r <= y)) {
          for(int j = 0; j < blocks[i].size(); j++) {
            if(j + x >= l && j + x <= r) (ans *= blocks[i].E[j]) %= MOD;
          }
        }
        x = y + 1;
      }
      printf("%lld\n", ans);
    }

    if(query_cnt == buffer) {
      if(blocks[0].size() > 0) {
        flatten();
        decompose();
      }
      query_cnt = 0;
    }
  }
}
