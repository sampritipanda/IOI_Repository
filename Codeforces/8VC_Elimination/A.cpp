#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;

  int cnt = 0;

  for(int i = 0; i < N; i++) {
    int x = 0, y = 0;
    for(int j = i; j < N; j++) {
      if(S[j] == 'U') y--;
      else if(S[j] == 'D') y++;
      else if(S[j] == 'R') x++;
      else x--;

      if(x == 0 && y == 0) cnt++;
    }
  }

  cout << cnt << endl;
}
