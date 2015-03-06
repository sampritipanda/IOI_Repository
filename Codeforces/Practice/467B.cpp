// Fedor and New Game

#include <iostream>

using namespace std;

int main() {
  int n, m, k; cin >> n >> m >> k;
  int players[m + 1];
  for(int i = 0; i <= m; i++) cin >> players[i];

  int count = 0;
  for(int i = 0; i < m; i++){
    if(__builtin_popcount(players[i] ^ players[m]) <= k) count++;
  }

  cout << count << endl;
}
