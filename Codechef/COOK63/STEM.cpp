// Word Stem

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<string, set<int> > freq;
map<int, set<string> > freq2;

int main() {
  int T; cin >> T;

  while(T--) {
    freq.clear();
    freq2.clear();
    int N; cin >> N;

    for(int n = 1; n <= N; n++) {
      string T; cin >> T;
      for(int l = 1; l <= T.length(); l++) {
        bool found = false;
        for(int i = 0; i + l - 1 < T.length(); i++) {
          freq[T.substr(i, l)].insert(n);
        }
      }
    }

    for(auto it: freq) {
      if(it.second.size() == N) {
        freq2[it.first.length()].insert(it.first);
      }
    }

    if(freq2.size() == 0) cout << endl;
    else cout << *freq2.rbegin()->second.begin() << endl;
  }
}
