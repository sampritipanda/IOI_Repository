#include <iostream>
#include <algorithm>

using namespace std;

int freq[7];

int main() {
  for(int i = 0; i <= 777777777; i++) {
    freq[i % 7]++;
  }
  double ans = 0;
  for(int i = 0; i < 7; i++) {
    cout << i << ": " << freq[i] << endl;
    ans += (freq[i] * double(i))/777777777.0;
  }
  cout << ans << endl;
}
