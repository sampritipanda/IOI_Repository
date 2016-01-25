#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[51][51];

int main() {
  int N; cin >> N;

  for(int i = 0; i < (N * (N - 1))/2 - 1; i++) {
    int x, y; cin >> x >> y;
    A[min(x, y)][max(x, y)] = x;
  }

  int x = -1, y = -1;
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(A[i][j] == 0) {
        x = i, y = j;
        break;
      }
    }
    if(x != -1) break;
  }

  vector<int> S, T;
  for(int i = 1; i <= N; i++) {
    if(A[min(x, i)][max(x, i)] == x) S.push_back(i);
  }
  for(int i = 1; i <= N; i++) {
    if(A[min(y, i)][max(y, i)] == x) S.push_back(i);
  }

  bool pos = false;
  for(auto it: S) {
    if(A[min(it, x)][max(it, x)] == x && A[min(it, y)][max(it, y)] != y) {
      pos = true;
      break;
    }
  }

  if(pos) cout << x << " " << y << endl;
  else cout << y << " " << x << endl;
}
