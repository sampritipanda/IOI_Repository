// Infinite String

#include <string>
#include <algorithm>

using namespace std;

class InfiniteString {
  public:
  string equal(string s, string t) {
    if(s.length() > t.length()) swap(s, t);
    int n = s.length(), m = t.length();

    bool flag = true;
    for(int i = 0; i < m; i++){
      if(s[i % n] != t[i]) {
        flag = false;
        break;
      }
    }

    if(flag) return "Equal";
    else return "Not equal";
  }
};
