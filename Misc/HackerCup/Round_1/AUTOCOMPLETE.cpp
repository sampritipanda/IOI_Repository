// Autocomplete

#include <iostream>
#include <string>

using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct trie_node {
  int count = 0;
  trie_node* children[26] = { NULL };
  bool leaf = false;
};

void insert(trie_node* curr_node, string key){
  int length = key.length();

  for(int level = 0; level < length; level++) {
    curr_node->count++;
    int index = CHAR_TO_INDEX(key[level]);
    if(!curr_node->children[index]) {
      curr_node->children[index] = new trie_node;
    }
    curr_node = curr_node->children[index];
  }
  curr_node->leaf = true;
}

int search(trie_node* curr_node, string key) {
    int length = key.length();

    for(int level = 0; level < length; level++ ) {
        int index = CHAR_TO_INDEX(key[level]);
        if(curr_node->count == 1 && !curr_node->leaf) {
          return level + (level == 0);
        }
        curr_node = curr_node->children[index];
    }

    return length;
}

int main() {
  int T; cin >> T;

  for(int i = 1; i <= T; i++){
    int N; cin >> N;
    int count = 0;

    trie_node* trie = new trie_node;

    for(int j = 0; j < N; j++){
      string word; cin >> word;
      insert(trie, word);
      count += search(trie, word);
    }

    cout << "Case #" << i << ": " << count << endl;
  }
}
