#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > edges;
vector<vector<int> > A, B;
int C[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;
  A.resize(N + 1); B.resize(M + 1);

  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      C[i][j] = -1;
    }
  }

  for(int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    A[a].push_back(b);
    B[b].push_back(a);

    edges.push_back({a, b});
  }

  int maxDeg = 0;
  for(int i = 1; i <= N; i++) maxDeg = max(maxDeg, (int)A[i].size());
  for(int i = 1; i <= M; i++) maxDeg = max(maxDeg, (int)B[i].size());
}
