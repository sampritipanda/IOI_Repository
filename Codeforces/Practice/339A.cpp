// Helpful Maths

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;
  int count_1 = 0, count_2 = 0, count_3 = 0;
  for(auto c: s){
    if(c == '1') count_1++;
    else if(c == '2') count_2++;
    else if(c == '3') count_3++;
    else continue;
  }
  string n = "";
  while(count_1--) n += "1+";
  while(count_2--) n += "2+";
  while(count_3--) n += "3+";
  if(n[n.length() - 1] == '+') n[n.length() - 1] = ' ';

  cout << n << endl;
}
