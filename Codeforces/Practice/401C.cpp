// Team

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int zero, ones; cin >> zero >> ones;

  if(zero >= ones) {
    if(zero - ones <= 1) {
      while(ones > 0) {
        cout << 0 << 1;
        zero--; ones--;
      }
      if(zero > 0) cout << 0;
    }
    else cout << -1;
  }
  else {
    if(ones - zero <= 1) {
      while(zero > 0) {
        cout << 1 << 0;
        ones--; zero--;
      }
      if(ones > 0) cout << 1;
    }
    else {
      string ans = "";
      while(ones > 0 || zero > 0) {
        if(ones == 0) {
          ans += '0';
          zero--;
        }
        else if(zero == 0) {
          ans += '1';
          ones--;
        }
        else {
          if(ones - zero > 0) {
            ans += "11";
            ans += '0';
            ones -= 2; zero--;
          }
          else {
            ans += '1';
            ans += '0';
            ones--; zero--;
          }
        }
      }

      bool correct = true;
      for(int i = 1; i < ans.length(); i++) {
        if(ans[i] == '0' && ans[i - 1] == '0') correct = false;
        if(i >= 2 && ans[i] == '1' && ans[i] == ans[i - 1] && ans[i] == ans[i - 2]) correct = false;
      }

      if(!correct) ans = "-1";
      cout << ans;
    }
  }
  cout << endl;
}
