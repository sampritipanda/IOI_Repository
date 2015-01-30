// Anton and currency you all know

#include <iostream>
#include <string>

using namespace std;

int main() {
  string N; cin >> N;
  int len = N.length();
  string max = N;
  bool first = true;
  for(int i = 0; i < len - 1; i++){
    int digit = N[i] - '0';
    if(digit % 2 == 0){
      string t = N;
      char temp = t[i];
      t[i] = t[len - 1];
      t[len - 1] = temp;

      if(t > max || first) {
        max = t;
        first = false;
      }
    }
  }

  if(N == max) cout << -1 << endl;
  else {
    cout << max << endl;
  }
}
