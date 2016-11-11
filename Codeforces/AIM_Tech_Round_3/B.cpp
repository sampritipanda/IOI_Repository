#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int a_00, a_01, a_10, a_11; cin >> a_00 >> a_01 >> a_10 >> a_11;

  if(a_01 == 0 && a_10 == 0) {
    if(a_00 == 0 && a_11 == 0) cout << "B" << endl;
    else if(a_00 > 0 && a_11 > 0) cout << "Impossible" << endl;
    else if(a_00 > 0) {
      for(int i = 0; i < a_00 + 1; i++) cout << "0";
      cout << endl;
    }
    else if(a_11 > 0) {
      for(int i = 0; i < a_11 + 1; i++) cout << "1";
      cout << endl;
    }
  }
  else if(a_01 == a_10) {
    for(int i = 0; i < a_00 + 1; i++) cout << "0";
    for(int i = 0; i < a_11 + 1; i++) cout << "1";
    for(int i = 0; i < a_01 - 1; i++) cout << "01";
    cout << "0" << endl;
  }
  else if(a_01 == a_10 + 1) {
    for(int i = 0; i < a_00 + 1; i++) cout << "0";
    for(int i = 0; i < a_11 + 1; i++) cout << "1";
    for(int i = 0; i < a_01 - 1; i++) cout << "01";
    cout << endl;
  }
  else if(a_10 == a_01 + 1) {
    for(int i = 0; i < a_11 + 1; i++) cout << "1";
    for(int i = 0; i < a_00 + 1; i++) cout << "0";
    for(int i = 0; i < a_01 - 1; i++) cout << "10";
    cout << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}
