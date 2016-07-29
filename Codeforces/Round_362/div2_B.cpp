#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  string S; cin >> S;
  string A = "", D = "";
  int B = 0;

  A = S[0];
  int i = 2;
  while(S[i] != 'e') {
    D += S[i];
    i++;
  }
  i++;
  while(i < S.length()) {
    B = B * 10 + (S[i] - '0');
    i++;
  }

  string ans = "";
  ans += A[0];
  reverse(D.begin(), D.end());
  while(D.length() > 0 && B--) {
    ans += D.back();
    D.pop_back();
  }
  if(B > 0) {
    while(B--) {
      ans += '0';
    }
  }

  if(D.length() > 0) {
    ans += '.';
    reverse(D.begin(), D.end());
    ans += D;
  }

  if(ans[1] != '.') {
    reverse(ans.begin(), ans.end());
    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
  }

  if(ans.length() > 2 && ans[ans.length() - 1] == '0' && ans[ans.length() - 2] == '.') {
    ans.pop_back();
    ans.pop_back();
  }
  cout << ans << endl;
}
