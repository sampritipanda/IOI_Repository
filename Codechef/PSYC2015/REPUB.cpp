// The Republic Day speech

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;
  getchar();
  map<char, int> freq;

  while(T--){
    string s;
    getline(cin, s);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(char c: s){
      if(c >= 'a' && c <= 'z') freq[c]++;
    }

    int max_freq = -1;
    char max_freq_letter = ' ';
    for(auto it: freq){
      if(max_freq == -1){
        max_freq = it.second;
        max_freq_letter = it.first;
      }
      else if(it.second > max_freq){
        max_freq = it.second;
        max_freq_letter = it.first;
      }
      else if(it.second == max_freq) max_freq_letter = it.first;
    }

    cout << max_freq_letter << endl;
    freq.clear();
  }
}
