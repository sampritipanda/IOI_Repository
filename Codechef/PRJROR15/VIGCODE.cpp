#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char table[26][26];
const string keyword = "FUSION";

int main() {
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      table[i][j] = 'A' + ((j + i) % 26);
    }
  }

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    string T = S;
    string final = S;

    for(int i = 0; i < N; i++) {
      T[i] = keyword[i % keyword.length()];
    }

    for(int j = 0; j < N; j++) {
      for(int i = 0; i < 26; i++) {
        if(table[i][T[j] - 'A'] == S[j]) {
          final[j] = 'A' + i;
          break;
        }
      }
    }

    cout << final << endl;
  }
}
