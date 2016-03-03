#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>

using namespace std;

struct node {
  int cnt;
  int end_id;
  int children[26];

  node() {
    for(int i = 0; i < 26; i++) children[i] = -1;
    cnt = 0;
    end_id = 0;
  }
};

int id = 0;
vector<node> trie;
vector<string> W;
vector<int> ans;
int N; string T;

void insert(string S, int index) {
  int i = 0;
  for(char c: S) {
    trie[i].cnt++;
    if(trie[i].children[c - 'a'] == -1) {
      trie.push_back(node());
      trie[i].children[c - 'a'] = ++id;
    }
    i = trie[i].children[c - 'a'];
  }
  trie[i].end_id = index;
  trie[i].cnt++;
}

bool solve(int i) {
  if(i == N) return true;

  int root = 0;
  for(int j = i; j < N; j++) {
    int ch = T[j] - 'a';
    if(trie[root].children[ch] == -1) break;
    root = trie[root].children[ch];

    if(trie[root].end_id != 0) {
      ans.push_back(trie[root].end_id);
      bool result = solve(j + 1);
      if(result) return true;
      else ans.pop_back();
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  trie.push_back(node());

  cin >> N;
  cin >> T;

  int M; cin >> M;
  W.push_back("-1");
  for(int i = 1; i <= M; i++) {
    string curr; cin >> curr; 
    string lower = curr; reverse(lower.begin(), lower.end());
    for(int j = 0; j < curr.size(); j++) lower[j] = tolower(lower[j]);

    W.push_back(curr);
    insert(lower, i);
  }

  solve(0);

  for(int i: ans) {
    cout << W[i] << " ";
  }
  cout << endl;
}
