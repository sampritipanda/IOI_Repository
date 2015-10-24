#include <vector>
#include <string>
#include <iostream>

using namespace std;

class GoodString {
  public:
  string isGood(string s) {
    int N = s.length();
    int curr = 0;
    bool possible = true;

    for(int i = 0; i < N; i++) {
      if(s[i] == 'a') curr++;
      else curr--;

      if(curr < 0) possible = false;
    }
    if(curr != 0) possible = false;

    if(possible) return "Good";
    else return "Bad";
  }
};

int main() {
  GoodString test;
  cout << test.isGood("abba") << endl;
}

