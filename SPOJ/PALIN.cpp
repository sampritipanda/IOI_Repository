#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isPalindrome(string s) {
  int len = s.length();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - 1 - i]) return false;
  }
  return true;
}

int main() {
  int T; cin >> T;

  while(T--){
    string N; cin >> N;
    int len = N.length();

    if(N.find_first_not_of('9') == string::npos){
      cout << "1";
      for(int i = 0; i < len - 1; i++){
        cout << "0";
      }
      cout << "1" << endl;
    }
    else if(isPalindrome(N)){
      int carry = 1, i = len/2;
      if(len % 2 == 0) i--;
      while(carry > 0 && i >= 0){
        int sum = N[i] - '0' + carry;
        carry = sum / 10;
        N[i] = (sum % 10) + '0';
        N[len - i - 1] = N[i];

        i--;
      }
    }
    else {
      bool addition_required = false;
      for(int i = 0; i < len/2; i++){
        N[len - i - 1] = N[i];
        if(N[i] < N[len - i - 1]){
          addition_required = true;
        }
      }

      if(addition_required){
        int carry = 1, i = len/2;
        if(len % 2 == 0) i--;
        while(carry > 0 && i >= 0){
          int sum = N[i] - '0' + carry;
          carry = sum / 10;
          N[i] = (sum % 10) + '0';
          N[len - i - 1] = N[i];

          i--;
        }
      }
    }

    cout << N << endl;
  }
}
