// Corporate Gifting

#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long solve(int curr, vector<vector<int> >& tree, int parents[], vector<set<int> >& gifts){
  // Leaf Node
  if(tree[curr].empty()) {
    gifts[parents[curr]].insert(1);
    return 1LL;
  }

  long long subtree_cost = 0;
  for(auto sub: tree[curr]){
    subtree_cost += solve(sub, tree, parents, gifts);
  }
  long long i = 1;
  while(gifts[curr].find(i) != gifts[curr].end()) i++;

  gifts[parents[curr]].insert(i);
  return subtree_cost + i;
}

int main() {
  int T; cin >> T;

  for(int i = 1; i <= T; i++){
    int N; cin >> N;
    vector<vector<int> > tree(N + 1);
    vector<set<int> > gifts(N + 1);
    int parents[N + 1];

    for(int i = 1; i <= N; i++){
      cin >> parents[i];
      tree[parents[i]].push_back(i);
    }

    long long max_cost = solve(1, tree, parents, gifts);
    cout << "Case #" << i << ": " << max_cost << endl;
  }
}
