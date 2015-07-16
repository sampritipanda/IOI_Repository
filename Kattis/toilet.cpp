// Toilet Seat

#include <iostream>
#include <string>

using namespace std;

int main() {
  string S; cin >> S;
  int N = S.length();
  int first = 0, second = 0, third = 0;

  char curr = S[0];
  for(int i = 1; i < N; i++){
    if(S[i] != curr) first++;
    if(S[i] != 'U') first++;
    curr = 'U';
  }

  curr = S[0];
  for(int i = 1; i < N; i++){
    if(S[i] != curr) second++;
    if(S[i] != 'D') second++;
    curr = 'D';
  }

  curr = S[0];
  for(int i = 1; i < N; i++){
    if(S[i] != curr) third++;
    curr = S[i];
  }

  cout << first << endl;
  cout << second << endl;
  cout << third << endl;
}
