#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

#define in cin
#define out cout

struct LCA
{
    vector<int> L, D;
    vector<vector<int> > P;
    int N;
    LCA(vector<int>  dad, vector<int>  level)
    {
        N = dad.size();
        D = dad,         L = level;
        int LOG = 1,     base = 1;

        while(base < N)
            LOG++, base <<= 1;

        P.resize(N, vector<int>(LOG, -1));

        for (int i = 0; i < N; i++)
            P[i][0] = D[i];

        for (int j = 1; 1 << j < N; j++)
            for (int i = 0; i < N; i++)
                if (P[i][j - 1] != -1)
                    P[i][j] = P[P[i][j - 1]][j - 1];
    }

    int query(int p, int q)
    {
        int tmp, log, i;
        if (L[p] < L[q])
            tmp = p, p = q, q = tmp;

        for (log = 1; 1 << log <= L[p]; log++);
        log--;

        for (i = log; i >= 0; i--)
            if (L[p] - (1 << i) >= L[q])
                p = P[p][i];

        if (p == q)
            return p;

        for (i = log; i >= 0; i--)
            if (P[p][i] != -1 && P[p][i] != P[q][i])
                p = P[p][i], q = P[q][i];

            return D[p];
    }
};

const int maxn = 50005;
vector<int> G[maxn];
int dad[maxn], level[maxn];
int A[maxn], B[maxn], ans[maxn];
int N;

int dfs(int u, int p, int l) {
  if(dad[u] >= 0) return 0;
  dad[u] = p;
  level[u] = l;

  int its = 0;
  for(auto it: G[u]) {
    dfs(it, u, l+1);
  }
}

int dfs2(int i) {
  int x = A[i];
  for(auto v: G[i]) {
    if(v != dad[i]) x += dfs2(v);
  }
  ans[i] = x - B[i];
  x -= 2 * B[i];
  return x;
}

int main() {
  ifstream in("maxflow.in");
  ofstream out("maxflow.out");

  in >> N;
  int K; in >> K;

  for(int i = 0; i < N - 1; i++) {
    int a, b; in >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 0; i < maxn; i++) dad[i] = -2;
  dfs(0, N, 0);
  dad[0] = -1;

  LCA lca( vector<int>(dad, dad+N), vector<int>(level, level + N));

  memset(A, 0, sizeof A);
  memset(B, 0, sizeof B);
  memset(ans, 0, sizeof ans);

  while(K--) {
    int u, v; in >> u >> v; u--; v--;
    int l = lca.query(u, v);

    A[u]++; A[v]++;
    B[l]++;
  }

  dfs2(0);

  int m = 0;
  for(int i = 0; i < N; i++) {
    m = max(m, ans[i]);
  }

  out << m << endl;
}

