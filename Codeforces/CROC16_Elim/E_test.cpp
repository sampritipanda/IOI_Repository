#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> A;

int main() {
  string S; cin >> S;
  int N = S.length();

  for(int mask = 0; mask < (1 << N); mask++) {
    string curr = "";
    for(int i = 0; i < N; i++) {
      if(mask & (1 << i)) {
        curr += S[i];
      }
    }
    A.insert(curr);
  }

  cout << A.size() << endl;
}
