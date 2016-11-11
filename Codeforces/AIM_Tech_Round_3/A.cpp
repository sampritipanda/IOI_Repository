#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  string S; cin >> S;
  int N = S.length();

  bool picked = false;
  int i;
  for(i = 0; i < N; i++) {
    if(S[i] != 'a') {
      picked = true;
      break;
    }
  }
  for(; i < N; i++) {
    if(S[i] == 'a') break;
    S[i]--;
  }

  if(!picked) {
    S[N - 1] = 'z';
  }

  cout << S << endl;
}
