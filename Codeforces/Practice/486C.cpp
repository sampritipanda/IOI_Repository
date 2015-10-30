// Palindrome Transformation

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int N, P; cin >> N >> P;
  string S, T, temps; cin >> S;
  T = S; temps = S; reverse(T.begin(), T.end());

  if(S == T) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;

  if(N % 2 == 0) {
    if(P > N/2) P = N - P + 1;
  }
  else {
    if(P == N/2 + 1) P--, ans++;
    else if(P > N/2 + 1) P = N - P + 1;
  }

  int x, y;
  for(x = 1; x <= P; x++) {
    if(S[x - 1] != T[x - 1]) break;
  }
  for(y = (N + 1)/2; y >= P; y--) {
    if(S[y - 1] != T[y - 1]) break;
  }

  int temp = P;
  int try1 = 0, try2 = 0, build_up = 0;
  for(; P >= x; P--) {
    if(S[P - 1] != T[P - 1]) {
      try1 += build_up; build_up = 0;
      try1 += min(abs(S[P - 1] - T[P - 1]), min(S[P - 1], T[P - 1]) + 26 - max(S[P - 1], T[P - 1]));
      S[P - 1] = T[P - 1];
    }
    build_up++;
  }
  if(x <= temp) P++;
  build_up = 0;
  for(; P <= y; P++) {
    if(S[P - 1] != T[P - 1]) {
      try1 += build_up; build_up = 0;
      try1 += min(abs(S[P - 1] - T[P - 1]), min(S[P - 1], T[P - 1]) + 26 - max(S[P - 1], T[P - 1]));
      S[P - 1] = T[P - 1];
    }
    build_up++;
  }

  build_up = 0, P = temp;
  S = temps, T = temps;
  reverse(T.begin(), T.end());

  for(; P <= y; P++) {
    if(S[P - 1] != T[P - 1]) {
      try2 += build_up; build_up = 0;
      try2 += min(abs(S[P - 1] - T[P - 1]), min(S[P - 1], T[P - 1]) + 26 - max(S[P - 1], T[P - 1]));
      S[P - 1] = T[P - 1];
    }
    build_up++;
  }
  if(y >= temp) P--;
  build_up = 0;
  for(; P >= x; P--) {
    if(S[P - 1] != T[P - 1]) {
      try2 += build_up; build_up = 0;
      try2 += min(abs(S[P - 1] - T[P - 1]), min(S[P - 1], T[P - 1]) + 26 - max(S[P - 1], T[P - 1]));
      S[P - 1] = T[P - 1];
    }
    build_up++;
  }

  cout << ans + min(try1, try2) << endl;
}
