#include <iostream>

using namespace std;

bool A[26];

int main() {
  string S; cin >> S;

  for(char c: S) A[c - 'a'] = true;

  int N; cin >> N;

  while(N--) {
    string W; cin >> W;

    bool pos = true;
    for(char c: W) {
      pos &= A[c - 'a'];
    }
    if(pos) cout << "Yes";
    else cout << "No";
    cout << endl;
  }
}

