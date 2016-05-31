#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string A, B; cin >> A >> B;
  map<char, int> M;
  for(char c: A) M[c]++;

  bool pos = true;
  for(char c: B) {
    if(c == '*') continue;
    if(M[c] == 0) {
      pos = false;
      break;
    }
    M[c]--;
  }

  if(A.length() != B.length()) pos = false;

  cout << (pos ? 'A' : 'N') << endl;
}
