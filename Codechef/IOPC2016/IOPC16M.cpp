#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;
    int Q; cin >> Q;

    long long num_bottom = 0;
    long long level = 0;
    for(long long i = 60; i >= 0; i--) {
      if(N & (1LL << i)) {
        level = (1LL << i);
        num_bottom = N - level + 1;
        break;
      }
    }

    while(Q--) {
      long long x; cin >> x;
      vector<long long> A;
      long long temp_x = x;
      while(temp_x) {
        A.push_back(temp_x);
        temp_x /= 2;
      }
      A.pop_back();
      reverse(A.begin(), A.end());

      long long ans = N, prev = 1, temp_level = level, temp_num_bottom = num_bottom;
      for(auto curr: A) {
        temp_level /= 2;
        long long new_N = temp_level - 1;
        if(curr == prev * 2) {
          if(temp_level < temp_num_bottom) {
            new_N += temp_level;
            temp_num_bottom = temp_level;
          }
          else {
            new_N += temp_num_bottom;
          }
        }
        else {
          new_N += max(temp_num_bottom - temp_level, 0LL);
          temp_num_bottom = max(temp_num_bottom - temp_level, 0LL);
        }
        ans = new_N;
        prev = curr;
      }

      cout << (ans + 1)/2 << endl;
    }
  }
}
