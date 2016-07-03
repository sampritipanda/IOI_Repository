#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int A[1501][1501];
int P[1501][1501];
bitset<1501> B[1501];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      char c; cin >> c;
      A[i][j] = c - '0';
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      P[i][j] = A[i][j] ^ P[i - 1][j] ^ P[i][j - 1] ^ P[i - 1][j - 1];
      if(P[i][j]) B[i].set(j);
    }
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) {
      bitset<1501> temp = B[j - 1] ^ B[i];
      int x = temp.count();
      ans += (x * (x - 1))/2;
      ans += ((M + 1 - x) * ((M + 1 - x) - 1))/2;
    }
  }
  cout << ans << endl;
}
