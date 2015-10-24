#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string S; cin >> S;
  bool cards[4][14];
  for(int i = 0; i < 4; i++) 
    for(int j = 0; j <= 13; j++) 
      cards[i][j] = false;

  bool fail = false;
  for(int i = 0; i < S.length(); i += 3) {
    char deck = S[i];
    int x;
    if(deck == 'P') x = 0;
    else if(deck == 'K') x = 1;
    else if(deck == 'H') x = 2;
    else x = 3;

    int y = (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
    if(cards[x][y]) {
      fail = true;
      break;
    }
    else {
      cards[x][y] = true;
    }
  }

  if(fail) cout << "GRESKA" << endl;
  else {
    for(int i = 0; i < 4; i++) {
      int sum = 0;
      for(int j = 1; j <= 13; j++) {
        if(!cards[i][j]) sum++;
      }
      cout << sum << " ";
    }
    cout << endl;
  }
}
