#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int F[256], F_req[256];
int diff;

void change(int x, int v) {
  if(F[x] == F_req[x]) diff++;
  F[x] += v;
  if(F[x] == F_req[x]) diff--;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int G, N; cin >> G >> N;

  string W; cin >> W;
  for(char c: W) F_req[c]++;

  for(int i = 0; i < 256; i++) {
    if(F[i] != F_req[i]) diff++;
  }

  string S; cin >> S;

  int i, ans = 0;
  for(i = 0; i < G; i++) change(S[i], 1);
  if(diff == 0) ans++;

  for(; i < N; i++) {
    change(S[i], 1);
    change(S[i - G], -1);
    if(diff == 0) ans++;
  }

  cout << ans << endl;
}
