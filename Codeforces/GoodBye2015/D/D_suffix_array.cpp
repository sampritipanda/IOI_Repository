#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

// http://codeforces.com/blog/entry/4025
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
const int MAXN = 5001;
string S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
int m[MAXN][14];

bool sufCmp(int i, int j)
{
  if (pos[i] != pos[j])
    return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
  N = S.size();
  REP(i, N) sa[i] = i, pos[i] = S[i];
  for (gap = 1;; gap *= 2)
  {
    sort(sa, sa + N, sufCmp);
    REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
    REP(i, N) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break;
  }
}

void buildLCP()
{
  for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
  {
    for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
      ++k;
    lcp[pos[i]] = k;
    if (k)--k;
  }
}

void buildTable() {
  for (int i = 0; i < N; i++)
    m[i][0] = lcp[i];

  for(int i = 1;(1 << i) <= N; i++) {
    for (int j = 0; j + (1 << i) - 1 < N; j++) {
      m[j][i] = min(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
    }
  }
}

int query(int i, int j) {
  int t = (int)(log(j - i + 1) / log(2));
  int p = 1 << t;
  return min(m[i][t], m[j - p + 1][t]);
}

long long dp[5001][5001];

bool check(int a, int b, int c, int d) {
  if(S[a] == '0' || S[c] == '0') return false;
  if(a == c && b == d) return false;

  int len_1 = b - a + 1, len_2 = d - c + 1;

  if(len_1 < len_2) return true;
  else if(len_1 > len_2) return false;
  else {
    int x = min(pos[a], pos[c]), y = max(pos[a], pos[c]);
    int l = query(x + 1, y);

    if(l >= len_1) return false;
    else if(S[a + l] < S[c + l]) return true;
    else return false;
  }
}

long long solve(int i, int j) {
  if(i > N) return 0;
  if(i == N) return 1;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = 0;
  ans += solve(i + 1, j);
  ans %= MOD;

  if(N - i >= i - j) {
    if(check(j, i - 1, i, i + (i - j) - 1)) ans += solve(i + (i - j), i);
    else ans += solve(i + (i - j) + 1, i);
  }
  ans %= MOD;

  return dp[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> S;

  buildSA();
  buildLCP();
  for(int i = N - 1; i > 0; i--) lcp[i] = lcp[i - 1];
  lcp[0] = 0;

  buildTable();

  for(int i = 0; i <= 5000; i++) {
    for(int j = 0; j <= 5000; j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(1, 0) << endl;
}
