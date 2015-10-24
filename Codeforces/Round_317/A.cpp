// Lengthening Sticks

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c, l; cin >> a >> b >> c >> l;

  vector<int> test = {a, b, c}; sort(test.begin(), test.end());
  a = test[0], b = test[1], c = test[2];

  if(a + b < c) {
  }
  else if(a + b == c){
  }
}
