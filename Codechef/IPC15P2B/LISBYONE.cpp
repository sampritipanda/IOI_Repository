#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int A[1001];
map<int, int> compres;
vector<int> bit;

int query(int i) {
  i = 2005 - i;
  int ans = 0;
  while(i > 0) {
    ans = max(ans, bit[i]);
    i -= i & -i;
  }
  return ans;
}

void update(int i, int x) {
  i = 2005 - i;
  while(i < 2005) {
    bit[i] = max(bit[i], x);
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  bit.resize(2005);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      compres[A[i]] = 0;
    }

    int timer = 0;
    for(auto it: compres) {
      compres[it.first] = 2*timer + 1;
      timer++;
    }

    for(int i = 1; i <= N; i++) A[i] = compres[A[i]];

    fill(bit.begin(), bit.end(), 0);

    for(int i = N - 1; i >= 0; i--) {
    }
  }
}
