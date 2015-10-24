#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long C[201][201];

int main() {
  for(int i = 1; i <= 200; i++) {
    for(int j = 1; j <= i; j++) {
      if(i == 1 && j == 1) C[i][j] = 1;
      else if(j == 0) C[i][j] = 1;
      else if(j == 1) C[i][j] = i;
      else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }

  int T; cin >> T;

  while(T--) {
    int N, M; cin >> N >> M;
    cout << C[N + M - 1][M - 1] << endl;
  }
}
