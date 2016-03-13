#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > A;
vector<vector<vector<pair<int, int> > > > G; // G[i][j] = neighbours of {i, j}

int main() {
  int N, M; cin >> N >> M;

  A.resize(N, vector<int>(M));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
}
