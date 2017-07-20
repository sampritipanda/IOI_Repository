#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  int c; cin >> c; N--;
  int L = INT_MIN/2, R = c;
  while(N--) {
    int nxt; cin >> nxt;
    int L_ = c + (c - R);
    int R_ = c + (c - L);
    assert(L_ <= R_);
    if(L_ > nxt) {
      cout << 0 << endl;
      return 0;
    }
    R_ = min(R_, nxt);
    L = L_; R = R_;
    c = nxt;
  }
  cout << R - L + 1 << endl;
}
