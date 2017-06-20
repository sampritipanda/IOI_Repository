#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  string S, T; cin >> S >> T;

  multiset<char> A, B;
  set<int> I;
  int N = S.length();
  string ans = "";
  for(int i = 0; i < N; i++) ans += '?';

  for(char c: S) A.insert(c);
  for(char c: T) B.insert(c);
  for(int i = 0; i < N; i++) I.insert(i);

  int moves_0 = 0, moves_1 = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) moves_0++;
    else moves_1++;
  }
  while(A.size() > moves_0) {
    A.erase(A.find(*A.rbegin()));
  }
  while(B.size() > moves_1) {
    B.erase(B.begin());
  }

  int turn = 0;
  while(!I.empty()) {
    if(turn == 0) {
      if(B.empty() || *A.begin() < *B.rbegin()) {
        int i = *I.begin();
        ans[i] = *A.begin();
        A.erase(A.begin());
        I.erase(I.begin());
      }
      else {
        int i = *I.rbegin();
        ans[i] = *A.rbegin();
        A.erase(A.find(*A.rbegin()));
        I.erase(I.find(i));
      }
    }
    else {
      if(A.empty() || *B.rbegin() > *A.begin()) {
        int i = *I.begin();
        ans[i] = *B.rbegin();
        B.erase(B.find(*B.rbegin()));
        I.erase(I.begin());
      }
      else {
        int i = *I.rbegin();
        ans[i] = *B.begin();
        B.erase(B.begin());
        I.erase(I.find(i));
      }
    }
    turn ^= 1;
  }
  cout << ans << endl;
}
