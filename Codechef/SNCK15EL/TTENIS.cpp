#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    int i = 0;
    int A = 0, B = 0;
    char win = '-';
    for(i = 0; i < N; i++) {
      if(S[i] == '1') A++;
      else B++;

      if(A == 10 && B == 10) {
        i++;
        break;
      }
      if(A == 11) {
        win = 'A';
        break;
      }
      else if(B == 11) {
        win = 'B';
        break;
      }
    }
    if(A == 11) win = 'A';
    else if(B == 11) win = 'B';

    if(win == '-') {
      for(; i < N; i++) {
        if(S[i] == '1') A++;
        else B++;

        if(A - B == 2) {
          win = 'A';
          break;
        }
        else if(B - A == 2) {
          win = 'B';
          break;
        }
      }
    }

    if(win == 'A') cout << "WIN" << endl;
    else cout << "LOSE" << endl;
  }
}
