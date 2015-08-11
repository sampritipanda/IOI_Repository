#include <iostream>

using namespace std;

#define MOD_VAL 1000000007

long long C[4010][4010];
long long bell[4010];

int main() {

  for (int i = 0; i <= 4000; i++)
  {
    for (int j = 0; j <= min(i, 4000); j++)
    {
      if (j == 0 || j == i)
        C[i][j] = 1;

      else
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD_VAL;
    }
  }

  int N; cin >> N;
  bell[0] = bell[1] = 1;
  bell[2] = 2;
  bell[3] = 5;

  for (int i = 4; i <= 4000; ++i) {
    for (int j = 0; j < i; ++j) {
      bell[i] += bell[j] * C[i - 1][j];
      bell[i] %= MOD_VAL;
    }
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += (C[N][i] * bell[N - i]) % MOD_VAL;
    ans %= MOD_VAL;
  }

  cout << ans << endl;
}
