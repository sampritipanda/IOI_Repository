#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string s; cin >> s;
    int N = s.length();
    int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
    for(auto c: s) freq[c - 'a']++;

    bool possible = true;
    for(int i = 0; i < N; i++){
      if(freq[i] > (N + 1) / 2) possible = false;
    }

    if(possible) {
      vector<pair<int, int> > letters;
      for(int i = 0; i < 26; i++) {
        letters.push_back({freq[i], i});
      }
      int k = 0;
      int last = -1;
      while(k < N) {
        vector<pair<int, int> > temp_l;
        for(int i = 0; i < letters.size(); i++) {
          if(letters[i].first > 0) temp_l.push_back(letters[i]);
        }
        letters = temp_l;
        sort(letters.begin(), letters.end(), greater<pair<int, int> >());
        if(last == -1) {
          cout << char(letters[0].second + 'a');
          last = letters[0].second;
          letters[0] = {letters[0].first - 1, letters[0].second};
        }
        else {
          for(int i = 0; i < letters.size(); i++) {
            if(letters[i].second != last) {
              cout << char(letters[i].second + 'a');
              last = letters[i].second;
              letters[i] = {letters[i].first - 1, letters[i].second};
            }
          }
        }
        k++;
      }
      cout << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
}
