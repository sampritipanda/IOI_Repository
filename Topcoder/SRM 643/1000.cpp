// The Kings Tree

#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class TheKingsTree {
  public:
  int getNumber(vector <int> parent){
    int N = parent.size() + 1;
    vector<vector<int> > tree(N);

    for(int i = 1; i <= N - 1; i++){
      tree[parent[i - 1]].push_back(i);
    }

    stack<int> S;
    queue<int> Q;
    Q.push(0);

    while (Q.empty() == false) {
      int root = Q.front();
      Q.pop();
      S.push(root);

      for(auto it = tree[root].rbegin(); it != tree[root].rend(); it++){
        Q.push(*it);
      }
    }

    vector<pair<int, int> > subtree_vals(N + 1);
    for(int i = 0; i <= N; i++) {
      subtree_vals[i].first = 0;
      subtree_vals[i].second = 0;
    }

    int R_total = 0, G_total = 0;

    while(S.empty() == false){
      int curr = S.top();
      S.pop();

      if(tree[curr].size() == 0){
        subtree_vals[curr].first++;
        R_total++;
      }
      else {
        int curr_total_R = 0, curr_total_G = 0;
        for(auto it = tree[curr].begin(); it != tree[curr].end(); it++){
          curr_total_R += subtree_vals[*it].first;
          curr_total_G += subtree_vals[*it].second;
        }

        subtree_vals[curr].first = curr_total_R;
        subtree_vals[curr].second = curr_total_G;
      }
    }

    int cost = 0;
    for(int i = N - 1; i >= 0; i--){
      cost += min(subtree_vals[i].first, subtree_vals[i].second) + 1;
    }

    return cost;
  }
};

int main() {
  TheKingsTree test;
  int myints[] = {0, 1, 2, 3, 4};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << test.getNumber(fifth) << endl;
}
