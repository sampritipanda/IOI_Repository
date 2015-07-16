// Bawdy Boil-brained Bugbear

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

vector<string> words_1, words_2, words_3;
vector<int> strength_1, strength_2, strength_3;
set<pair<int, pair<int, int> > > done;
map<int, vector<int> > search_set;

int find_index(vector<string>& word_list, string S) {
  return find(word_list.begin(), word_list.end(), S) - word_list.begin();
}

int main() {
  int M; cin >> M;

  for(int i = 0; i < M; i++) {
    string S; int strength; cin >> S >> strength;
    words_1.push_back(S);
    strength_1.push_back(strength);
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    string S; int strength; cin >> S >> strength;
    words_2.push_back(S);
    strength_2.push_back(strength);
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    string S; int strength; cin >> S >> strength;
    words_3.push_back(S);
    strength_3.push_back(strength);
    search_set[strength].push_back(i);
  }

  int N; cin >> N;
  while(N--) {
    string word_1, word_2, word_3; cin >> word_1 >> word_2 >> word_3;
    int strength = strength_1[find_index(words_1, word_1)] + strength_2[find_index(words_2, word_2)] + strength_3[find_index(words_3, word_3)];
    strength++;

    for(int i = 0; i < M; i++) {
      bool flag = false;
      for(int j = 0; j < M; j++) {
        int rem = strength - (strength_1[i] + strength_2[j]);
        if(rem < 0) continue;

        if(search_set.find(rem) == search_set.end()) continue;
        for(auto k: search_set[rem]) {
          if(done.find({i, {j, k}}) == done.end()) {
            done.insert({i, {j, k}});
            cout << words_1[i] << " " << words_2[j] << " " << words_3[k] << endl;
            flag = true;
            break;
          }
        }
        if(flag) break;
      }
      if(flag) break;
    }
  }
}

