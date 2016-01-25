// Chandragupta and the fun with BST

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MOD 1000000007

struct node {
  int val = 0;
  int L = -1, R = -1;
};

vector<node> BST;
int id = 0;
map<int, int> ans;
int A[300001];

void insert(int x, int i) {
  if(BST[i].val == 0) {
    BST[i].val = x;
    return;
  }

  if(x < BST[i].val) {
    if(BST[i].L == -1) {
      BST[i].L = id++;
      BST.push_back(node());
    }
    insert(x, BST[i].L);
  }
  else {
    if(BST[i].R == -1) {
      BST[i].R = id++;
      BST.push_back(node());
    }
    insert(x, BST[i].R);
  }
}

void dfs(int i, long long val) {
  ans[BST[i].val] = val;

  if(BST[i].L != -1) dfs(BST[i].L, (2*val) % MOD);
  if(BST[i].R != -1) dfs(BST[i].R, (2*val + 1) % MOD);
}

int main() {
  ios::sync_with_stdio(false);
  BST.push_back(node()); id++;

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    insert(A[i], 0);
  }

  dfs(0, 1);

  for(int i = 0; i < N; i++) cout << ans[A[i]] << " "; cout << endl;
}

