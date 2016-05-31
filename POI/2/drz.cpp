#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int A[2505];
vector<int> G[10001];
int N = 0;
vector<int> ans1;
string ans2;
int timer = 0;

void dfs(int i, int p) {
  ans1.push_back(p);
  int id = ++timer;
  ans2 += '(';

  for(int j = 0; j < G[i].size(); j++) {
    dfs(G[i][j], id);
  }

  ans2 += ')';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M; cin >> M;

  vector<pair<int, int> > layer;
  for(int i = 1; i <= M; i++) {
    int x; cin >> x;
    layer.push_back(make_pair(x, ++N));
  }

  while(layer.size() != 1) {
    vector<pair<int, int> > new_layer;
    bool changed = false;

    int max_level = -1;
    for(int i = 0; i < layer.size(); i++) max_level = max(max_level, layer[i].first);

    for(int i = 0; i < layer.size(); i++) {
      if(i < int(layer.size() - 1) && layer[i].first == max_level && layer[i].first == layer[i + 1].first) {
        changed = true;
        int par_id = ++N;
        G[par_id].push_back(layer[i].second);
        G[par_id].push_back(layer[i + 1].second);
        new_layer.push_back(make_pair(layer[i].first - 1, par_id));
        i++;
      }
      else {
        new_layer.push_back(layer[i]);
      }
    }

    if(!changed) break;
    layer = new_layer;
  }

  if(layer.size() > 1 || layer[0].first != 0) {
    cout << "NIE" << endl;
    return 0;
  }

  int root = layer[0].second;

  dfs(root, 0);

  for(int i = 0; i < ans1.size(); i++) {
    cout << ans1[i];
    if(i < int(ans1.size()) - 1) cout << " ";
    else cout << endl;
  }
  cout << ans2 << endl;
}
