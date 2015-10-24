// Mårten's Theorem

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct trie_node {
  vector<int> partial, ending;
  trie_node* children[26];
};

vector<int> yes_union_find, no_union_find;
vector<pair<pair<unsigned long long, unsigned long long>, int> > queries;
unordered_map<unsigned long long, int> word_map;
int N = 0;

int find(vector<int>& arr, int a) {
  if(arr[a] == a) return a;
  else return arr[a] = find(arr, arr[a]);
}

void merge(vector<int>& arr, int a, int b) {
  a = find(arr, a), b = find(arr, b);
  arr[b] = a;
}

void form_relations(trie_node* root, string word, int id) {
  reverse(word.begin(), word.end());
  word = word.substr(0, min(int(word.length()), 3));

  for(int i = 0; i < word.length(); i++) {
    if(root->children[word[i] - 'a'] == NULL) root->children[word[i] - 'a'] = new trie_node;
    root = root->children[word[i] - 'a'];

    for(auto a: root->ending) {
      merge(yes_union_find, id, a);
    }
    if(i < word.length() - 1) root->partial.push_back(id);
  }

  for(auto a: root->partial) {
    merge(yes_union_find, id, a);
  }
  root->ending.push_back(id);
}

unsigned long long find_hash(string s) {
  unsigned long long a = 5381;
  for(auto c: s) a = ((a << 5) + a) + c;
  return a;
}

int main() {
  yes_union_find.push_back(0); no_union_find.push_back(0);

  trie_node* root = new trie_node;

  int Q; cin >> Q;

  bool valid = true;
  while(Q--) {
    string a_orig, type, b_orig; cin >> a_orig >> type >> b_orig;
    unsigned long long a = find_hash(a_orig), b = find_hash(b_orig);

    int id_a, id_b;
    if(word_map.count(a) == 0) {
      id_a = word_map[a] = ++N;
      yes_union_find.push_back(id_a); no_union_find.push_back(id_a);
      form_relations(root, a_orig, id_a);
    }
    if(word_map.count(b) == 0) {
      id_b = word_map[b] = ++N;
      yes_union_find.push_back(id_b); no_union_find.push_back(id_b);
      form_relations(root, b_orig, id_b);
    }
    id_a = word_map[a], id_b = word_map[b];

    if(type == "is") {
      queries.push_back({{a, b}, 0});
      if(id_a != id_b && find(no_union_find, id_a) == find(no_union_find, id_b)) {
        valid = false;
        break;
      }
      merge(yes_union_find, id_a, id_b);
    }
    else {
      queries.push_back({{a, b}, 1});
      if(id_a == id_b || find(yes_union_find, id_a) == find(yes_union_find, id_b)) {
        valid = false;
        break;
      }
      merge(no_union_find, id_a, id_b);
    }
  }

  if(valid) {
    for(auto q: queries) {
      int id_a = word_map[q.first.first], id_b = word_map[q.first.second];
      if(q.second == 0) {
        if(id_a != id_b && find(no_union_find, id_a) == find(no_union_find, id_b)) {
          valid = false;
          break;
        }
      }
      else {
        if(id_a == id_b || find(yes_union_find, id_a) == find(yes_union_find, id_b)) {
          valid = false;
          break;
        }
      }
    }
  }

  if(valid) cout << "yes" << endl;
  else cout << "wait what?" << endl;
}
