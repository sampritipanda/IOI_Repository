#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <climits>

using namespace std;

#define LIM 150

int B[30000], P[30000];
set<int> A[30000];
int D[30000][LIM + 1];
set<pair<int, pair<int, int> > > Q;

void update(int i, int j, int d) {
  if(D[i][j] != INT_MAX/2) {
    Q.erase({D[i][j], {i, j}});
  }
  D[i][j] = d;
  Q.insert({D[i][j], {i, j}});
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 0; i < M; i++) {
    cin >> B[i] >> P[i];
    A[B[i]].insert(P[i]);
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= LIM; j++) {
      D[i][j] = INT_MAX/2;
    }
  }

  int ans = -1;

  Q.insert({0, {B[0], LIM}}); D[B[0]][LIM] = 0;

  while(!Q.empty()) {
    auto it = *Q.begin(); Q.erase(Q.begin());
    int i = it.second.first, j = it.second.second;

    if(i == B[1]) {
      ans = it.first;
      break;
    }

    if(j == LIM) {
      for(int x: A[i]) {
        if(x < LIM) {
          if(D[i][j] < D[i][x]) {
            update(i, x, D[i][j]);
          }
        }
        else {
          for(int d = 1; i + d * x < N; d++) {
            if(A[i + d * x].size() == 0) continue;
            if(D[i][j] + d < D[i + d * x][LIM]) {
              update(i + d * x, LIM, D[i][j] + d);
            }
            // if(A[i + d * x].count(x)) break;
          }
          for(int d = 1; i - d * x >= 0; d++) {
            if(A[i - d * x].size() == 0) continue;
            if(D[i][j] + d < D[i - d * x][LIM]) {
              update(i - d * x, LIM, D[i][j] + d);
            }
            // if(A[i - d * x].count(x)) break;
          }
        }
      }
    }
    else {
      if(D[i][j] < D[i][LIM]) {
        update(i, LIM, D[i][j]);
      }

      if(i + j < N && D[i][j] + 1 < D[i + j][j]) {
        update(i + j, j, D[i][j] + 1);
      }
      if(i - j >= 0 && D[i][j] + 1 < D[i - j][j]) {
        update(i - j, j, D[i][j] + 1);
      }
    }
  }

  cout << ans << endl;
}
