// Decipherability 

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DecipherabilityEasy {
  public:
  string check(string s, string t) {
    int N = s.length();
    for(int i = 0; i < N; i++){
      string temp(s);
      temp.erase(i, 1);
      if(temp == t) return "Possible";
    }
    return "Impossible";
  }
};

int main() {
  DecipherabilityEasy test;
  cout << test.check("sunuke", "snuke") << endl;
}

