#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[5001];
int A[5001][5001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  bool found = false;

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < G[i].size(); j++) {
      for(int k = j + 1; k < G[i].size(); k++) {
        int x = G[i][j], y = G[i][k];

        if(A[x][y]) {
          found = true;
          cout << "TAIP" << endl;
          cout << i << " " << x << " " << A[x][y] << " " << y << endl;
          break;
        }
        A[x][y] = A[y][x] = i;
      }
      if(found) break;
    }
    if(found) break;
  }

  if(!found) cout << "NE" << endl;
}
