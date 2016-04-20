#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int Q; cin >> Q;

  while(Q--) {
    int N, u, v; cin >> N >> u >> v;
    if(u > v) swap(u, v);

    if(u == v) {
      cout << N << endl;
      continue;
    }

    int l_u = floor(log2(u)), l_v = floor(log2(v));
    u <<= l_v - l_u;

    if(u == v) {
      v++;
    }
    if(N < v) {
      cout << 1 << endl;
      continue;
    }

    int diff_bit = -1;
    for(int i = 30; i >= 0; i--) {
      if((u & (1 << i)) != (v & (1 << i))) {
        diff_bit = i;
        break;
      }
    }

    int A = 0, B = 0;
    for(int i = diff_bit; i >= 0; i--) {
      if(u & (1 << i)) A |= (1 << i);
      if(v & (1 << i)) B |= (1 << i);
    }
    if(A > B) swap(A, B);

    N -= B;

    cout <<  N/(1 << (diff_bit + 1)) << endl;
  }
}
