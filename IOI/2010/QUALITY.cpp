#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[3001][3001];
int P[3001][3001];
int N, M;
int H, W;

bool check(int X) {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
      if(A[i][j] <= X) P[i][j]--;
      else P[i][j]++;
    }
  }

  for(int i = H; i <= N; i++) {
    for(int j = W; j <= M; j++) {
      int curr = P[i][j] - P[i - H][j] - P[i][j - W] + P[i - H][j - W];
      if(curr <= 0) return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> H >> W;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }

  int L = 1, R = N * M;

  while(L < R) {
    int mid = (L + R)/2;

    if(check(mid)) R = mid;
    else L = mid + 1;
  }

  cout << L << endl;
}
