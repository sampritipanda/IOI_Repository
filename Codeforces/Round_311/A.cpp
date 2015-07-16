// Ilya and Diplomas

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  int min1, max1; cin >> min1 >> max1;
  int min2, max2; cin >> min2 >> max2;
  int min3, max3; cin >> min3 >> max3;

  int ans1 = min1, ans2 = min2, ans3 = min3;
  int remaining = N - (min1 + min2 + min3);

  if(remaining > 0) {
    if(max1 < remaining + ans1) {
      remaining -= max1 - ans1;
      ans1 = max1;
    }
    else {
      ans1 += remaining;
      remaining = 0;
    }
  }
  if(remaining > 0) {
    if(max2 < remaining + ans2) {
      remaining -= max2 - ans2;
      ans2 = max2;
    }
    else {
      ans2 += remaining;
      remaining = 0;
    }
  }
  if(remaining > 0) {
    if(max3 < remaining + ans3) {
      remaining -= max3 - ans3;
      ans3 = max3;
    }
    else {
      ans3 += remaining;
      remaining = 0;
    }
  }

  cout << ans1 << " " << ans2 << " " << ans3 << endl;
}
