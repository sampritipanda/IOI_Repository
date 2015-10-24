// Lucky Division

#include <iostream>
#include <vector>

using namespace std;

bool lucky(int n) {
  while(n > 0) {
    int dig = n % 10;
    if(dig != 7 && dig != 4) return false;
    n /= 10;
  }
  return true;
}

int main() {
  vector<int> nums;
  for(int i = 1; i <= 1000; i++) {
    if(lucky(i)) nums.push_back(i);
  }

  int N; cin >> N;

  bool flag = false;
  for(auto it: nums) {
    if(it > N) break;
    if(N % it == 0) {
      flag = true;
      break;
    }
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
