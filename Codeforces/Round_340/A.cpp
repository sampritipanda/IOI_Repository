#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int X; cin >> X;

  int count = 0;
  while(X > 0) {
    X -= 5;
    count++;
  }
  if(X > 0) count++;

  cout << count << endl;
}
