#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int A[501];
vector<vector<int> > ops;

// add j * d to i
void update(int i, int j, int d) {
  for(int bit = 30; bit >= 0; bit--) {
    if(d & (1 << bit)) {
      ops.push_back({i, j, bit});
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  vector<int> pos, neg;
  for(int i = 1; i <= N; i++) {
    if(A[i] > 0) pos.push_back(i);
    else if(A[i] < 0) neg.push_back(i);
  }

  if((pos.size() + neg.size() != 1) && (pos.size() == 0 || neg.size() == 0)) {
    cout << 0 << endl;
  }
  else {
    while(true) {
      if(pos.size() + neg.size() == 1) break;

      // i = index to remove, j = number used
      int i, j;
      if(pos.size() > neg.size()) {
        i = pos.back();
        j = neg.back();
        pos.pop_back();
      }
      else {
        i = neg.back();
        j = pos.back();
        neg.pop_back();
      }

      int x = A[i], y = A[j];
      while(true) {
        if(x == 0) {
          A[i] = 0;
          A[j] = y;
          break;
        }
        int a = abs(x), b = abs(y);

        if(a < b) {
          if(b % a == 0) {
            update(j, i, (b/a) - 1);
            y = -x;
          }
          else {
            update(j, i, b/a);
            y += x * (b/a);
          }
        }
        else {
          update(i, j, a/b);
          x += y * (a/b);
        }
      }
    }

    cout << 1 << endl;
    cout << ops.size() << endl;
    for(auto it: ops) cout << it[0] << " " << it[1] << " " << it[2] << endl;
  }
}
