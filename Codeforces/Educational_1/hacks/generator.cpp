#include <iostream>

using namespace std;

int main() {
  for(int i = 0; i < 10000; i++) cout << 'a';
  cout << endl;

  cout << 300 << endl;
  for(int i = 0; i < 300; i++) {
    cout << 1 << " " << 10000 << " " << 9999 << endl;
  }
}

