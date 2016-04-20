#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    string S; cin >> S;
    deque<char> A;

    for(auto c: S) {
      if(A.size() == 0) A.push_back(c);
      else {
        if(c >= A.front()) A.push_front(c);
        else A.push_back(c);
      }
    }

    cout << "Case #" << t << ": ";
    for(auto it: A) cout << it;
    cout << endl;
  }
}
