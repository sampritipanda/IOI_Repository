#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 10) - 1;
const lld LINF = (1LL << 62) - 1;

int T;
int DP[50][50][60];

int compute(int n, int m, int k) {
  if (n <= 0 || m <= 0 || k <= 0)
    return 0;

  if (n * m == k)
    return 0;

  if (DP[n][m][k] >= 0)
    return DP[n][m][k];

  DP[n][m][k] = INF;

  for (int i = 1; i < n; i++)
    for (int j = 0; j <= k; j++)
      DP[n][m][k] = min(DP[n][m][k], compute(i, m, j) + compute(n - i, m, k - j) + m * m);

  for (int i = 1; i < m; i++)
    for (int j = 0; j <= k; j++)
      DP[n][m][k] = min(DP[n][m][k], compute(n, i, j) + compute(n, m - i, k - j) + n * n);

  return DP[n][m][k];
}

int main() {
  int n, m, k;

  cin.sync_with_stdio(false);


  scanf("%d", &T);

  for (int i = 0; i <= 30; i++)
    for (int j = 0; j <= 30; j++)
      for (int k = 0; k <= 50; k++)
        DP[i][j][k] = -1;

  for (int i = 1; i <= 30; i++)
    for (int j = 1; j <= 30; j++)
      for (int k = 1; k <= min(i * j, 50); k++)
        DP[i][j][k] = compute(i, j, k);

  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", compute(n, m, k));
  }

  return 0;
}
