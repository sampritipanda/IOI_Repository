#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int convert(char C) {
  if(C >= '0' && C <= '9') return C - '0';
  if(C >= 'A' && C <= 'Z') return C - 'A' + 10;
  if(C >= 'a' && C <= 'z') return C - 'a' + 36;
  if(C == '-') return 62;
  return 63;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  string S; cin >> S;
  long long ans = 1;

  for(char c: S) {
    int x = convert(c);

    for(int i = 0; i < 6; i++) {
      if(!(x & (1 << i))) ans = (ans * 3) % MOD;
    }
  }

  cout << ans << endl;
}
