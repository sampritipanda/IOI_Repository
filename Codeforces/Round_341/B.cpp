#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1001][1001];

int main() {
  ios::sync_with_stdio(false);

  int N; cin >> N;

  while(N--) {
    int x, y; cin >> x >> y;

    A[x][y] = 1;
  }

  long long ans = 0;

  for(int j2 = 1; j2 <= 1000; j2++) {
    int i = 1, j = j2;
    long long cnt = 0;
    while(i <= 1000 && j <= 1000) {
      cnt += A[i][j];
      i += 1; j += 1;
    }
    ans += (cnt * (cnt - 1))/2;
  }

  for(int i2 = 2; i2 <= 1000; i2++) {
    int j = 1, i = i2;
    long long cnt = 0;
    while(i <= 1000 && j <= 1000) {
      cnt += A[i][j];
      i += 1; j += 1;
    }
    ans += (cnt * (cnt - 1))/2;
  }

  for(int j2 = 1000; j2 >= 1; j2--) {
    int i = 1, j = j2;
    long long cnt = 0;
    while(i <= 1000 && j >= 1) {
      cnt += A[i][j];
      i += 1; j -= 1;
    }
    ans += (cnt * (cnt - 1))/2;
  }

  for(int i2 = 2; i2 <= 1000; i2++) {
    int j = 1000, i = i2;
    long long cnt = 0;
    while(i <= 1000 && j >= 1) {
      cnt += A[i][j];
      i += 1; j -= 1;
    }
    ans += (cnt * (cnt - 1))/2;
  }

  cout << ans << endl;
}
