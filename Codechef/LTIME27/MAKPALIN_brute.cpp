#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    int count = 0;
    for(int i = 0; i <= N; i++) {
      string temp = S;
      temp.insert(temp.begin() + i, '-');
      temp[i] = temp[(N + 1) - i - 1];
      string temp2 = temp; reverse(temp2.begin(), temp2.end());
      if(temp == temp2) count++;
    }
    cout << count << endl;
  }
}

