// Game

#include <iostream>

using namespace std;

int main() {
  int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
  int curr = 1;

  while(true){
    if(curr == 1){
      if(n1 == 0) break;
      n1--;
      curr = 2;
    }
    else {
      if(n2 == 0) break;
      n2--;
      curr = 1;
    }
  }

  cout << ((curr == 1) ? "Second" : "First") << endl;
}
