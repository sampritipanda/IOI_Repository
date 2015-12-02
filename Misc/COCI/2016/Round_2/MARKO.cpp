#include <iostream>
#include <string>
#include <vector>

using namespace std;

char get(char a) {
  if(a >= 'a' && a <= 'c') return '2';
  else if(a >= 'd' && a <= 'f') return '3';
  else if(a >= 'g' && a <= 'i') return '4';
  else if(a >= 'j' && a <= 'l') return '5';
  else if(a >= 'm' && a <= 'o') return '6';
  else if(a >= 'p' && a <= 's') return '7';
  else if(a >= 't' && a <= 'v') return '8';
  else if(a >= 'w' && a <= 'z') return '9';
}

vector<string> dict;

int main() {
  int N; cin >> N;
  dict.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> dict[i];
  }

  string seq; cin >> seq;

  int count = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < dict[i].length(); j++) {
      dict[i][j] = get(dict[i][j]);
    }
    if(dict[i] == seq) count++;
  }

  cout << count << endl;
}
