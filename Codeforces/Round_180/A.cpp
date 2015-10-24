// Parity Game

#include <iostream>

using namespace std;

int main() {
  string A, B; cin >> A >> B;
  int N = A.length(), M = B.length();
  int a_count = 0, b_count = 0;
  for(auto c: A) {
    if(c == '1') a_count++;
  }
  for(auto c: B) {
    if(c == '1') b_count++;
  }

  if(b_count - a_count > 1 || (a_count % 2 == 0 && a_count < b_count)) cout << "NO" << endl;
  else cout << "YES" << endl;
}
