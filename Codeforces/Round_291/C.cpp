// Watto and Mechanism

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct trie_node {
  trie_node* children[3] = { NULL, NULL, NULL };
};

void addToTrie(string s, trie_node* curr){
  for(auto t: s){
    if(curr->children[t - 'a'] == NULL) curr->children[t - 'a'] = new trie_node;
    curr = curr->children[t - 'a'];
  }
}

int returnIndex(string q, trie_node* curr){
  int N = q.length();
  int i = 0;
  for(i = 0; i < N; i++){
    if(curr->children[q[i] - 'a'] == NULL) break;
    curr = curr->children[q[i] - 'a'];
  }
  return i;
}

int main() {
  trie_node* root = new trie_node;
  vector<string> suffixes;
  int N, M; cin >> N >> M;

  for(int i = 0; i < N; i++){
    string s; cin >> s;
    addToTrie(s, root);
    int X = s.length();
    string temp = "";
    for(int j = 0; j < X; j++){
      temp += s[j];
      suffixes.push_back(temp);
    }
  }
  sort(suffixes.begin(), suffixes.end());

  for(int i = 0; i < M; i++){
    string q; cin >> q;
    int X = q.length();
    int j = returnIndex(q, root);
    if(j == X) {
      cout << "NO" << endl;
      continue;
    }
    else if(j == X - 1){
      cout << "YES" << endl;
      continue;
    }
    else {
      string check = "";
      for(int k = j + 1; k < X; k++) check += q[k];
      if(binary_search(suffixes.begin(), suffixes.end(), check)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}
