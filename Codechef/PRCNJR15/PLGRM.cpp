// N Boy and Palingrams

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    string R = S; reverse(R.begin(), R.end());
    bool palindrome = (R == S);
    bool chars[26]; for(int i = 0; i < 26; i++) chars[i] = false;
    for(auto c: S) {
      chars[c - 'a'] = true;
    }
    bool pangram = true;
    for(int i = 0; i < 26; i++) pangram = pangram && chars[i];

    if(palindrome && pangram) cout << "palingram" << endl;
    else if(palindrome) cout << "palindrome" << endl;
    else if(pangram) cout << "pangram" << endl;
    else cout << "none" << endl;
  }
}
