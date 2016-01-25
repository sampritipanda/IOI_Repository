// Misha and Forest

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int D[100000], S[100000];

int main() {
  int N; cin >> N;

  queue<int> Q;
  for(int i = 0; i < N; i++) {
    cin >> D[i] >> S[i];
    if(D[i] == 1) {
      Q.push(i);
    }
  }

  vector<pair<int, int> > edges;
  while(!Q.empty()) {
    int i = Q.front(); Q.pop();

    if(D[i] != 1) continue;

    int v = S[i];
    edges.push_back({i, v});
    D[i]--; D[v]--;
    S[i] ^= v; S[v] ^= i;

    if(D[v] == 1) Q.push(v);
  }

  cout << edges.size() << endl;
  for(auto it: edges) cout << it.first << " " << it.second << endl;
}
