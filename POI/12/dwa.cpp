// Gaussian Elimination from https://github.com/ADJA/algos/blob/master/NumberTheory/Gauss.cpp

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int MAXN = 201;
const int INF = 1 << 20;

int N, M;
vector<int> G[MAXN];
int a[MAXN][MAXN];
int ans[MAXN];

int gauss() {
  int pos[MAXN];
  memset(pos, 0, sizeof(pos));

  bool parameters = false;
  int row = 1, col = 1;

  for (; row <= N && col <= M; col++) {
    int pivot = row;
    for (int i = row; i <= N; i++)
      if (a[i][col] > a[pivot][col])
        pivot = i;

    if (a[pivot][col] == 0) {
      parameters = true;
      continue;
    }

    for (int i = 1; i <= M + 1; i++)
      swap(a[row][i], a[pivot][i]);

    pos[col] = row;

    int div = a[row][col];
    assert(div == 1);

    for (int i = 1; i <= N; i++) {
      if (i == row)
        continue;
      div = a[i][col];
      for (int j = 1; j <= M + 1; j++) {
        a[i][j] += a[row][j] * div;
        a[i][j] %= 2;
      }
    }

    row++;
  }

  for (int i = 1; i <= M; i++)
    if (pos[i] != 0)
      ans[i] = a[pos[i]][M + 1];
    else
      ans[i] = 0;

  if (parameters)
    return INF;

  return 1;
}

int main() {
  scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    int L; scanf("%d", &L);
    while(L--) {
      int x; scanf("%d", &x);
      G[i].push_back(x);
    }
  }

  M = N;

  for(int i = 1; i <= N; i++) {
    if(G[i].size() % 2 == 0) {
      for(int j = 0; j < G[i].size(); j++) {
        int u = G[i][j];
        a[i][u] = 1;
      }
      a[i][M + 1] = 0;
    }
    else {
      a[i][i] = 1;
      for(int j = 0; j < G[i].size(); j++) {
        int u = G[i][j];
        a[i][u] = 1;
      }
      a[i][M + 1] = 1;
    }
  }

  gauss();

  vector<int> ans_vec;
  for(int i = 1; i <= N; i++) {
    if(ans[i]) ans_vec.push_back(i);
  }

  printf("%d\n", (int)ans_vec.size());
  for(int i = 0; i < ans_vec.size(); i++) {
    printf("%d", ans_vec[i]);
    if(i + 1 == ans_vec.size()) printf("\n");
    else printf(" ");
  }
}
