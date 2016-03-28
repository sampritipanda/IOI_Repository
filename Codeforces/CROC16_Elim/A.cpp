#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strip(string A, string B) {
  reverse(B.begin(), B.end());
  string T = A + B;
  string ans = "";
  for(char c: T)
    if(c != 'X') ans += c;

  return ans;
}

int main() {
  string A, B, C, D; cin >> A >> B >> C >> D;

  string X = strip(A, B), Y = strip(C, D);
  string C1 = ""; C1 += Y[1]; C1 += Y[2]; C1 += Y[0];
  string C2 = ""; C2 += Y[2]; C2 += Y[0]; C2 += Y[1];

  if(X == Y || X == C1 || X == C2) cout << "YES" << endl;
  else cout << "NO" << endl;
}
