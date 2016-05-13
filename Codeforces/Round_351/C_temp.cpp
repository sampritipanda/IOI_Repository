#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

typedef double T;
const int N = (int)2e5 + 10;
T dp[2][N];
T inv_sum[N];
T sum_val[N];
T sum[N];
int t[N];

T block_cost (int l, int r)
{
/*
    T ans = 0;
    for (int i = l; i < r; i++)
    for (int j = l; j <= i; j++)
        ans += (T)t[j] / t[i];
    return ans;
*/
    T total = sum_val[r] - sum_val[l] - sum[l] * (inv_sum[r] - inv_sum[l]);
    return total;
}

int cur = 1;
const T inf = 1e100;

void work (int l, int r, int ls, int rs)
{
    if (r - l <= 1)
        return;

    int m = (l + r) / 2;
    int crs = min(rs, m);
    int cls = max(ls, 0);

    const int prev = cur ^ 1;
    T ans = inf;
    int ptr = -1;

    for (int i = cls; i <= crs; i++)
    if (dp[prev][i] + block_cost(i, m) < ans)
    {
        ans = dp[prev][i] + block_cost(i, m);
        ptr = i;
    }

    assert(ptr != -1);
    dp[cur][m] = ans;

    work(l, m, ls, ptr);
    work(m, r, ptr, rs);
}

void solve (int n, int k)
{
    for (int i = 0; i < n; i++)
        cin >> t[i];
     //   t[i] = rng() % 10 + 1;

    memset(sum, 0, sizeof sum);
    memset(sum_val, 0, sizeof sum_val);
    memset(dp, 0, sizeof dp);
    memset(inv_sum, 0, sizeof inv_sum);

    T cur_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cur_sum += 1.0 / (T)t[i - 1];
        inv_sum[i] = cur_sum;
        sum[i] = sum[i - 1] + t[i - 1];
        sum_val[i] = sum_val[i - 1] + sum[i] / (T)t[i - 1];
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << block_cost(i, j) << " ";
      }
      cout << endl;
    }

    for (int i = 0; i < N; i++)
        dp[0][i] = inf;
    dp[0][0] = 0;
    dp[1][0] = 0;

    for (int iter = 0; iter < k; iter++)
    {
        work(0, n + 1, 0, n + 1);
        cur ^= 1;
    }

    printf("%.20f\n", dp[cur ^ 1][n]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    n = (int)2e5, k = 50;
    while (cin >> n >> k)
        solve(n, k);
}
