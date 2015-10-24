// Chat room

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string S; cin >> S;
  string T = "hello";

  int N = S.length();
  int i = 0, j = 0;
  while(i < N && j < 5) {
    if(S[i] == T[j]) j++;
    i++;
  }

  if(j == 5) cout << "YES" << endl;
  else cout << "NO" << endl;
}
