// !(a ^ b) == (a | !b) & (b | !a)
// a ^ b == (a | b) & (!a | !b)
// !(u1 ^ v1) ^ !(u1 ^ v2) = (((u1 | !v1) & (v1 | !u1)) | ((u1 | !v2) & (v2 | !u1))) & (!((u1 | !v1) & (v1 | !u1)) | !((u1 | !v2) & (v2 | !u1)))


#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> G[201];

void print(long long mask, int N) {
  vector<int> ans_vec;
  for(int i = 0; i < N; i++) {
    if(mask & (1LL << i)) ans_vec.push_back(i + 1);
  }

  printf("%d\n", (int)ans_vec.size());
  for(int i = 0; i < ans_vec.size(); i++) {
    printf("%d", ans_vec[i]);
    if(i + 1 == ans_vec.size()) printf("\n");
    else printf(" ");
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    int L; scanf("%d", &L);
    while(L--) {
      int x; scanf("%d", &x); x--;
      G[i].push_back(x);
    }
  }

  for(long long mask = 0; mask < (1LL << N); mask++) {
    int curr = 0;

    for(int i = 0; i < N; i++) {
      int c = (mask & (1LL << i)) ? 1 : 0;
      int cnt = 0;
      for(int j = 0; j < G[i].size(); j++) {
        int u = G[i][j];
        int c2 = (mask & (1LL << u)) ? 1 : 0;
        if(c == c2) cnt++;
      }
      if(cnt % 2 == 0) curr++;
    }

    if(curr == N) {
      print(mask, N);
    }
  }
}
