#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> A;

int main() {
  for(int i = 2; i <= 60; i++) {
    long long x = 1LL << i; x--;
    for(int j = 0; j < i - 1; j++) {
      long long y = 1LL << j;
      A.push_back(x - y);
    }
  }

  sort(A.begin(), A.end());
  unique(A.begin(), A.end());

  long long P, Q; cin >> P >> Q;
  int ans = 0;
  for(auto it: A) {
    if(it >= P && it <= Q) ans++;
  }
  cout << ans << endl;
}
