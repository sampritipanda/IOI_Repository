#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();

    int left = 0, right = 0;

    for(int i = 0; S[i] != 'W'; i++) left++;
    for(int i = N - 1; S[i] != 'W'; i--) right++;

    if(left != right) cout << "Aleksa" << endl;
    else cout << "Chef" << endl;
  }
}
