#include <iostream>

#define MOD 1000000000

using namespace std;

long long dp_row[2001][2001];
long long dp_table[2001][2001];
long long prefix_dp_table[2001][2001];

int main() {
  int T; cin >> T;

  while(T--){
    int N, M; cin >> N >> M;

    for(int j = 0; j <= M; j++) {
      dp_row[1][j] = 1;
    }
    for(int i = 1; i <= M; i++) {
      dp_row[i][0] = 1;
    }
    for(int i = 2; i <= M; i++) {
      for(int j = 1; j <= M; j++) {
        dp_row[i][j] = dp_row[i - 1][j] + dp_row[i][j - 1];
        dp_row[i][j] %= MOD;
      }
    }

    for(int j = 0; j <= M; j++) {
      dp_table[1][j] = dp_row[M][j];
    }
    for(int i = 1; i <= N; i++) {
      dp_table[i][0] = 1;
    }

    prefix_dp_table[1][0] = dp_table[1][0];
    for(int j = 1; j <= M; j++)  prefix_dp_table[1][j] = (prefix_dp_table[1][j - 1] + dp_table[1][j]) % MOD;

    for(int i = 2; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        dp_table[i][j] = prefix_dp_table[i - 1][j] * dp_row[M][j];
        dp_table[i][j] %= MOD;
      }

      prefix_dp_table[i][0] = dp_table[i][0];
      for(int j = 1; j <= M; j++) prefix_dp_table[i][j] = (prefix_dp_table[i][j - 1] + dp_table[i][j]) % MOD;
    }

    cout << prefix_dp_table[N][M] << endl;
  }
}
