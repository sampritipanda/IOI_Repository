// Value of String

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class ValueOfString {
  public:
  int findValue(string s) {
    int ans = 0;
    int N = s.length();
    for(int i = 0; i < N; i++){
      int count = 0;
      for(int j = 0; j < N; j++) {
        if(s[j] <= s[i]) count++;
      }
      ans += count * (s[i] - 'a' + 1);
    }
    return ans;
  }
};

