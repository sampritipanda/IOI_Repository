// Ancestors Sum

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long parent[100005];
set<int> tree[100005];
bool visited[100005];
bool leaf[100005];
int size[100005];
int heavy_child[100005];
int chain_head[100005];
map<int, vector<int> > chains;
int path_index[100005];
map<int, vector<long long> > bi_trees;

void dfs_parent(int i){
  int out_degree = 0;
  size[i] = 1;
  for(auto v: tree[i]){
    if(v == parent[i]) continue;

    parent[v] = i;
    out_degree++;
    dfs_parent(v);
    size[i] += size[v];
  }

  int max_size = 0, max_node = -1;
  for(auto v: tree[i]) {
    if(v == parent[i]) continue;

    if(size[v] > max_size) {
      max_size = size[v];
      max_node = v;
    }
  }
  heavy_child[i] = max_node;

  if(out_degree == 0) leaf[i] = true;
}

void update(vector<long long>& bit, int pos, int val){
  pos++;
  for(; pos < bit.size(); pos += pos & -pos){
    bit[pos] += val;
  }
}

long long query(vector<long long>& bit, int R){
  R++;
  long long sum = 0;
  for(; R > 0; R -= R & -R){
    sum += bit[R];
  }
  return sum;
}

int main() {
  int N; cin >> N;

  for(int i = 0; i < N - 1; i++){
    int u, v; cin >> u >> v;
    tree[u].insert(v);
    tree[v].insert(u);
  }

  parent[0] = -1;
  dfs_parent(0);

  vector<int> path;
  for(int i = 0; i < N; i++){
    if(!leaf[i]) continue;

    path.clear();
    int l = i;
    while(l != -1 && !visited[l]){
      path.push_back(l);
      visited[l] = true;
      if(parent[l] == -1 || heavy_child[parent[l]] != l) break;
      l = parent[l];
    }
    for(auto it: path){
      chain_head[it] = path.back();
    }
    int index = 0;
    for(auto it = path.rbegin(); it != path.rend(); it++){
      chains[chain_head[*it]].push_back(*it);
      path_index[*it] = index++;
    }
  }

  for(auto it: chains){
    bi_trees[it.first].resize(it.second.size() + 1);
  }

  int Q; cin >> Q;
  while(Q--){
    char type; cin >> type;

    if(type == 'A'){
      int v, inc; cin >> v >> inc;
      update(bi_trees[chain_head[v]], path_index[v], inc);
    }
    else {
      int l; cin >> l;
      long long ans = 0;
      while(l != -1){
        ans += query(bi_trees[chain_head[l]], path_index[l]);
        l = parent[chain_head[l]];
      }
      cout << ans << endl;
    }
  }
}
