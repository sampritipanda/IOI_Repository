#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool vis[1000001];
pair<int, int> par[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int K; cin >> K;

  while(K--) {
    int N; cin >> N;

    for(int i = 0; i <= N; i++) {
      vis[i] = false;
      par[i] = make_pair(-1, -1);
    }

    queue<int> Q;
    Q.push(1 % N);
    vis[1 % N] = true;

    while(!Q.empty()) {
      int u = Q.front(); Q.pop();

      if(u == 0) break;

      int add_0 = (u * 10) % N;
      int add_1 = (u * 10 + 1) % N;

      if(!vis[add_0]) {
        vis[add_0] = true;
        par[add_0] = make_pair(u, 0);
        Q.push(add_0);
      }
      if(!vis[add_1]) {
        vis[add_1] = true;
        par[add_1] = make_pair(u, 1);
        Q.push(add_1);
      }
    }

    if(vis[0]) {
      string ans = "";
      int u = 0;
      while(true) {
        if(par[u].first == -1) break;
        ans += char('0' + par[u].second);
        u = par[u].first;
      }
      ans += '1';
      reverse(ans.begin(), ans.end());
      cout << ans << endl;
    }
    else {
      cout << "BRAK" << endl;
    }
  }
}
