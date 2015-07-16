// Trending Topic

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
  int day = 0;
  vector<string> words[7];
  map<string, int> dict;
  map<int, set<string> > reverse_dict;

  while(!cin.eof()) {
    string X; cin >> X;

    if(X == "<text>") {
      for(auto word: words[day]) {
        dict[word]--;
        if(dict[word] == 0) dict.erase(word);
      }
      words[day].clear();

      string word;
      cin >> word;
      while(word != "</text>") {
        if(word.length() >= 4) {
          words[day].push_back(word);
          dict[word]++;
        }

        cin >> word;
      }

      day = (day + 1) % 7;
    }
    else if(X == "<top") {
      int N; cin >> N;
      string temp_ignore; cin >> temp_ignore;

      reverse_dict.clear();
      for(auto it: dict) {
        if(it.second > 0) {
          reverse_dict[it.second].insert(it.first);
        }
      }

      int print_count = 0;
      cout << "<top " << N << ">" << endl;
      for(auto it = reverse_dict.rbegin(); print_count < N && it != reverse_dict.rend(); it++) {
        for(auto word: it->second) {
          cout << word << " " << it->first << endl;
          print_count++;
        }
      }
      cout << "</top>" << endl;
    }
  }
}
