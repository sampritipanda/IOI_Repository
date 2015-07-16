// Corrupted Message

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CorruptedMessage {
  public:
  string reconstructMessage(string s, int k) {
    int freq[26]; for(int i = 0; i < 26; i++) freq[i] = 0;
    int N = s.length();
    for(auto c: s){
      freq[c - 'a']++;
    }
    char maxChar = 'a';
    for(int i = 0; i < 26; i++){
      if((freq[i] + k) == N){
        maxChar = 'a' + i;
        break;
      }
    }

    string res = "";
    while(N--){
      res += maxChar;
    }

    return res;
  }
};

