#include <iostream>
#include <string>

using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;

  int A = 0, C = 0, G = 0, T = 0;
  for(auto c: s){
    if(c == 'A') A++;
    else if(c == 'C') C++;
    else if(c == 'G') G++;
    else T++;
  }

}
