#include <iostream>
#include <algorithm>

using namespace std;

bool vis[201][201][201];
bool done[3];  // 0 = blue, 1 = green, 2 = red

void solve(int b, int g, int r) {
  if(b + g + r == 1) {
    if(b == 1) done[0] = true;
    else if(g == 1) done[1] = true;
    else done[2] = true;
    return;
  }

  if(vis[b][g][r]) return;
  vis[b][g][r] = true;

  if(b >= 1 && g >= 1) solve(b - 1, g - 1, r + 1);
  if(b >= 1 && r >= 1) solve(b - 1, g + 1, r - 1);
  if(g >= 1 && r >= 1) solve(b + 1, g - 1, r - 1);

  if(b >= 2) solve(b - 1, g, r);
  if(g >= 2) solve(b, g - 1, r);
  if(r >= 2) solve(b, g, r - 1);
}

int main() {
  int N; cin >> N;
  string S; cin >> S;

  int b = 0, g = 0, r = 0;
  for(char c: S) {
    if(c == 'R') r++;
    else if(c == 'G') g++;
    else b++;
  }

  solve(b, g, r);

  if(done[0]) cout << 'B';
  if(done[1]) cout << 'G';
  if(done[2]) cout << 'R';

  cout << endl;
}
