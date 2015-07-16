#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    int digit_sum = 0;
    for(auto c: S) digit_sum = (digit_sum + (c - '0')) % 9;

    if(digit_sum == 0) cout << "0" << '\n';
    else {
      if(digit_sum <= 4) {
        bool possible_this_way = false;
        int curr_sum = 0;
        if(N > 1) curr_sum += S[0] - '1';
        for(int i = (N > 1 ? 1 : 0); i < N; i++) {
          curr_sum += S[i] - '0';
          if(curr_sum >= digit_sum) {
            possible_this_way = true;
            break;
          }
        }

        if(possible_this_way) cout << digit_sum << '\n';
        else cout << (9 - digit_sum) << '\n';
      }
      else {
        bool possible_this_way = false;
        int curr_sum = 0;
        for(int i = 0; i < N; i++) {
          curr_sum += 9 - (S[i] - '0');
          if(curr_sum >= (9 - digit_sum)) {
            possible_this_way = true;
            break;
          }
        }

        if(possible_this_way) cout << (9 - digit_sum) << '\n';
        else cout << digit_sum << '\n';
      }
    }
  }
}
