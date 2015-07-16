// Xor Queries

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

namespace XORQuery {
  class TrieNode {
    public:
    TrieNode* children[2];
    set<int> indexes;

    TrieNode() {
      children[0] = NULL;
      children[1] = NULL;
    }
  };

  void insert_node(int num, int idx, TrieNode* curr){
    for(int i = 19; i >= 0; i--){
      int bit = ((num & (1 << i)) != 0) ? 1 : 0;
      curr->indexes.insert(idx);
      if(curr->children[bit] == NULL) curr->children[bit] = new TrieNode;
      curr = curr->children[bit];
    }
    curr->indexes.insert(idx);
  }

  int query(int x, int L, int R, TrieNode* curr){
    int max = 0;
    for(int i = 19; i >= 0; i--){
      int bit = ((x & (1 << i)) != 0) ? 0 : 1;
      if(curr->children[bit] == NULL || curr->children[bit]->indexes.lower_bound(L) == curr->children[bit]->indexes.upper_bound(R)) {
        bit = (bit == 1) ? 0 : 1;
      }
      max = max << 1;
      max += bit;
      curr = curr->children[bit];
    }

    return max;
  }

  bool delete_node(int x, int idx, TrieNode* curr){
    for(int i = 19; i >= 0; i--){
      int bit = ((x & (1 << i)) != 0) ? 1 : 0;
      curr->indexes.erase(idx);
      if(curr->children[bit] == NULL) break;
      curr = curr->children[bit];
    }
    curr->indexes.erase(idx);
  };
}

int sort_query(vector<int>& arr, int L, int R, int x, int type){

  if(type == 3){
    int count = 0;
    for(int i = L; i <= R; i++) {
      if(arr[i] <= x) count++;
    }
    return count;
  }
  else {
    vector<int> range;
    for(int i = L; i <= R; i++){
      range.push_back(arr[i]);
    }
    sort(range.begin(), range.end());

    return range[x - 1];
  }
}

int main() {
  int M; scanf("%d", &M);
  vector<int> arr;
  XORQuery::TrieNode trie_root;
  int size = 0;

  for(int i = 0; i < M; i++){
    int type; scanf("%d", &type);

    if(type == 0){
      int x; scanf("%d", &x);
      arr.push_back(x);
      XORQuery::insert_node(x, size, &trie_root);
      size++;
    }
    else if(type == 1){
      int L, R, x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;

      printf("%d\n", XORQuery::query(x, L, R, &trie_root));
    }
    else if(type == 2){
      int k; scanf("%d", &k);
      for(int j = size - k; j < size; j++){
        XORQuery::delete_node(arr[j], j, &trie_root);
      }
      arr.resize(size - k);
      size -= k;
    }
    else {
      int L, R, x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;

      printf("%d\n", sort_query(arr, L, R, x, type));
    }
  }
}
