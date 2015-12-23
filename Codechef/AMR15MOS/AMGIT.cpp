#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, map<string, int> > tree;
int timer = 0;
map<int, int> A, B;

void insert(string S, int type, int i) {
  if(type == 1) A[i]++;
  else B[i]++;

  if(S == "") return;

  string tok = "";
  for(int i = 0; i < S.size() && A[i] != '/'; i++) {
    tok += S[i];
  }
  S.erase(0, tok.size());

  if(tree[i].count(tok) == 0) {
    tree[i][tok] = ++timer;
  }
  insert(S, type, tree[i][tok]);
}

int dfs(int i) {
  if(A[i] == 0) return 0;
  if(B[i] == 0) return 1;

  int ans = 0;
  for(auto it: tree[i]) {
    ans += dfs(it.second);
  }

  return ans;
}

int main() {
  int T; cin >> T;

  while(T--) {
    tree.clear(); A.clear(); B.clear();
    timer = 0;

    int N; cin >> N;

    for(int i = 0; i < N; i++) {
      string S, path; cin >> S >> path;
      int type = (S == "stage" ? 1 : 0);

      path.erase(0, 1);
      insert(path, type, 0);
    }

    cout << dfs(0) << endl;
  }
}
