#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
  node* children[26];
  int cnt;
  int depth;

  node() {
    for(int i = 0; i < 26; i++) children[i] = NULL;
    cnt = 0;
    depth = 0;
  }

  void insert(char* S, int i, int N) {
    if(i == N) {
      cnt++;
      return;
    }
    int x = S[i] - 'a';
    if(children[x] == NULL) children[x] = new node();
    children[x]->insert(S, i + 1, N);
    depth = max(depth, children[x]->depth + 1);
  }
};

vector<char> ans;

void dfs(node* curr) {
  while(curr->cnt--) {
    ans.push_back('P');
  }

  vector<pair<int, int> > nxt;
  for(int i = 0; i < 26; i++) {
    if(curr->children[i] == NULL) continue;
    nxt.push_back({curr->children[i]->depth, i});
  }
  sort(nxt.begin(), nxt.end());

  for(auto it: nxt) {
    int i = it.second;
    ans.push_back('a' + i);
    dfs(curr->children[i]);
    ans.push_back('-');
  }
}

int main() {
  node* root = new node();
  int N; scanf("%d", &N);

  char S[100];
  while(N--) {
    scanf("%s", &S);
    root->insert(S, 0, strlen(S));
  }

  dfs(root);

  while(ans.back() != 'P') {
    ans.pop_back();
  }

  printf("%d\n", ans.size());
  for(char c: ans) printf("%c\n", c);
}
