#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct node {
  node* C[26];

  node() {
    for(int i = 0; i < 26; i++) C[i] = NULL;
  }
};

void insert(node* root, string& S) {
  int N = S.length();
  for(int i = 0; i < N; i++) {
    int c = S[i] - 'a';
    if(root->C[c] == NULL) root->C[c] = new node();
    root = root->C[c];
  }
}

bool dfs(node* root) {
  for(int i = 0; i < 26; i++) {
    if(root->C[i] == NULL) continue;
    if(dfs(root->C[i]) == false) return true;
  }

  return false;
}

bool dfs2(node* root) {
  int cnt = 0;

  for(int i = 0; i < 26; i++) {
    if(root->C[i] == NULL) continue;
    cnt++;
    if(dfs2(root->C[i]) == false) return true;
  }

  if(cnt == 0) return true;
  return false;
}

int main() {
  int N, K; cin >> N >> K;

  node* trie = new node();

  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    insert(trie, S);
  }

  bool first_win = dfs(trie);
  bool first_lose = dfs2(trie);

  if(first_win) {
    if(first_lose) cout << "First" << endl;
    else {
      if(K % 2 == 1) cout << "First" << endl;
      else cout << "Second" << endl;
    }
  }
  else {
    cout << "Second" << endl;
  }
}
