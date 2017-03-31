#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string S; cin >> S;

  int pos[26];
  for(int i = 0; i < 26; i++) pos[i] = 10000;

  for(int i = 0; i < S.length(); i++) {
    pos[S[i] - 'a'] = min(pos[S[i] - 'a'], i);
  }

  bool ans = true;
  for(int i = 0; i < 25; i++) {
    if(pos[i] > pos[i + 1]) ans = false;
  }

  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}
