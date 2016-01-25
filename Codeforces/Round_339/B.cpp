#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  int zeroes = 0;
  string non_beatiful = "1";
  bool zero_ans = false;

  for(int i = 0; i < N; i++) {
    bool start = false;
    string S; cin >> S;
    int zero_count = 0;
    bool beau = true;
    for(auto c: S) {
      if(c != '0' && c != '1') {
        beau = false;
        break;
      }
      if(c == '1') {
        if(start) {
          beau = false;
          break;
        }
        start = true;
      }
    }

    if(!beau) {
      non_beatiful = S;
      continue;
    }

    start = false;
    for(auto c: S) {
      if(c == '0' && start) zero_count++;
      if(c == '1') start = true;
    }

    if(!start) zero_ans = true;
    else zeroes += zero_count;
  }

  if(zero_ans) cout << "0" << endl;
  else {
    cout << non_beatiful;
    while(zeroes--) {
      cout << '0';
    }
    cout << endl;
  }
}
