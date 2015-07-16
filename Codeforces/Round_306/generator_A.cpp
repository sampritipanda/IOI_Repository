#include <iostream>

using namespace std;

int main() {
  cout << "AB";
  for(int i = 1; i <= 100000 - 2; i++) cout << char('A' + i % 26);
  cout << endl;
}
