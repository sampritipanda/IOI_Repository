#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    map<string, int> M;

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
      string s; cin >> s;
      M[s]++;
    }

    deque<string> A; int x;
    x = M["bb"]/2; M["bb"] = M["bb"] - 2*x;
    for(int i = 0; i < x; i++) {
        A.push_front("bb"); A.push_back("bb");
    }
    x = min(M["ab"], M["ba"]);
    for(int i = 0; i < x; i++) {
        A.push_front("ab"); A.push_back("ba");
    }
    x = M["aa"]/2; M["aa"] = M["aa"] - 2*x;
    for(int i = 0; i < x; i++) {
        A.push_front("aa"); A.push_back("aa");
    }

    int sz = A.size();
    for(int i = 0; i < sz/2; i++) {
      cout << A[i];
    }
    if(M["aa"] == 1) cout << "aa";
    else if(M["bb"] == 1) cout << "bb";
    for(int i = sz/2; i < sz; i++) {
      cout << A[i];
    }
    cout << endl;
  }
}
