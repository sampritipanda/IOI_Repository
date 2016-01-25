#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct trie_node {
  trie_node* children[26];
};

string S;
int N;

int main() {
  cin >> S;
  N = S.length();

  trie_node* root = new trie_node;
}
