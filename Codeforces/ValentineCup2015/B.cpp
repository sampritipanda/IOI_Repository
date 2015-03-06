// Valentine's Restaurant

#include <iostream>

using namespace std;

int main() {
  cout << "([],1)" << endl;
  cout << "([1],1)" << endl;
  cout << "([11,[1)" << endl;

  for(int i = 1000; i > 1; i--){
    cout << "(";
    for(int j = 0; j < i; j++) cout << "1";
    cout << "," << i << ")" << endl;
  }

  return 0;
}
