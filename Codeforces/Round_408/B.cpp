#include <iostream>

using namespace std;

int H[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int x; cin >> x;
    H[x] = 1;
  }

  int curr = 1;
  while(K--) {
    if(H[curr]) break;
    int u, v; cin >> u >> v;
    if(curr == u) curr = v;
    else if(curr == v) curr = u;
  }
  cout << curr << endl;
}
