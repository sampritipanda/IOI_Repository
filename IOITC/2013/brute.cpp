#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
  int val = 0;
  int L = -1, R = -1;
};

vector<node> BST;
int id = 0;

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

void dfs(int i) {
  cout << char(BST[i].val + 'a');

  if(BST[i].L != -1) dfs(BST[i].L);
  if(BST[i].R != -1) dfs(BST[i].R);
}

int main() {
  ios::sync_with_stdio(false);
  BST.push_back(node()); id++;

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    char c; cin >> c;
    insert(c - 'a', 0);
  }

  dfs(0);
  cout << endl;
}

