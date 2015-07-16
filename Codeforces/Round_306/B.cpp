#include <iostream>
#include <climits>

using namespace std;

int main() {
  int n, l, r, x; cin >> n >> l >> r >> x;
  int c[n]; for(int i = 0; i < n; i++) cin >> c[i];

  int num_ways = 0;
  for(int mask = 0; mask < (1 << n); mask++) {
    int num = __builtin_popcount(mask);
    if(num < 2) continue;

    int sum = 0;
    int min_diff = INT_MAX, max_diff = 0;
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) {
        min_diff = min(min_diff, c[i]);
        max_diff = max(max_diff, c[i]);
        sum += c[i];
      }
    }
    if(sum >= l && sum <= r && (max_diff - min_diff) >= x) {
      num_ways++;
    }
  }
  cout << num_ways << endl;
}
