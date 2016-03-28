#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int val = 0, L = -1, R = -1;
};

vector<node> tree;
int timer = 0;
vector<int> A;

void insert(int i, int val) {
  if(tree[i].val == 0) {
    tree[i].val = val;
    return;
  }

  if(val < tree[i].val) {
    if(tree[i].L == -1) {
      tree.push_back(node());
      tree[i].L = timer++;
    }
    insert(tree[i].L, val);
  }
  else {
    if(tree[i].R == -1) {
      tree.push_back(node());
      tree[i].R = timer++;
    }
    insert(tree[i].R, val);
  }
}

void dfs(int i) {
  if(tree[i].R != -1) dfs(tree[i].R);
  if(tree[i].L != -1) dfs(tree[i].L);

  A.push_back(tree[i].val);
}

int main() {
  int N; cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  tree.push_back(node()); timer++;
  tree[0].val = A.back(); A.pop_back();

  while(!A.empty()) {
    insert(0, A.back());
    A.pop_back();
  }

  dfs(0);

  for(auto it: A) cout << it << endl;
}
