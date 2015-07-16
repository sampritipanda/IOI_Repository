// Misspell

#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main() {
  string str;
  getline(cin, str);
  istringstream S(str);

  int N; cin >> N;
  set<string> dict;
  while(N--){
    string word; cin >> word;
    dict.insert(word);
  }

  bool correct = true;
  while(!S.eof()){
    string word; S >> word;
    if(dict.find(word) == dict.end()){
      correct = false;
      break;
    }
  }

  if(correct) cout << "Correct" << endl;
  else cout << "Misspell" << endl;
}
