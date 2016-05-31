#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<pair<int, int> > A, B;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    int x, y; cin >> x >> y;
    if(x <= y) {
      A.push_back({x, y});
    }
    else {
      B.push_back({x, y});
    }
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());

  long long swap = 0, extra = 0;
  for(auto it: A) {
    if(swap + extra >= it.first) {
      extra += it.second - it.first;
    }
    else {
      swap += it.first - (swap + extra);
      extra += it.second - it.first;
    }
  }
  for(auto it: B) {
    if(swap + extra >= it.first) {
      extra += it.second - it.first;
    }
    else {
      swap += it.first - (swap + extra);
      extra += it.second - it.first;
    }
  }

  cout << swap << endl;
}
