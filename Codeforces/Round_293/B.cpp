// Tanya and Invitation

#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string s; cin >> s;
  string t; cin >> t;

  int N = s.length(), M = t.length();

  unordered_map<char, int> chars;
  for(auto c: t) chars[c]++;

  int yay = 0, whoops = 0;

  for(int i = 0; i < N; i++){
    if(chars[s[i]] > 0){
      chars[s[i]]--;
      s[i] = '.';
      yay++;
    }
  }

  for(int i = 0; i < N; i++){
    if(s[i] == '.') continue;

    if(chars[tolower(s[i])] > 0){
      chars[tolower(s[i])]--;
      s[i] = '.';
      whoops++;
    }
    else if(chars[toupper(s[i])] > 0){
      chars[toupper(s[i])]--;
      s[i] = '.';
      whoops++;
    }
  }

  cout << yay << " " << whoops << endl;
}
