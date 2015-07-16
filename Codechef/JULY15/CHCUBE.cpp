// Chef and Cube

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    string front, back, left, right, top, bottom; cin >> front >> back >> left >> right >> top >> bottom;
    bool possible = false;

    if(top == front && (front == right || front == left)) possible = true;
    else if(top == right && right == back) possible = true;
    else if(top == left && left == back) possible = true;
    else if(bottom == front && (front == right || front == left)) possible = true;
    else if(bottom == right && right == back) possible = true;
    else if(bottom == left && left == back) possible = true;

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
