// Combination Lock

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  string orig; cin >> orig;
  string required; cin >> required;

  int ans = 0;
  for(int i = 0; i < N; i++){
    int digit1 = orig[i] - '0';
    int digit2 = required[i] - '0';

    ans += min(abs(digit1 - digit2), min(10 - digit1 + digit2, digit1 + 10 - digit2));
  }

  cout << ans << endl;
}
