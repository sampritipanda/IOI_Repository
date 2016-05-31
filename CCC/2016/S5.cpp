#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, bool> M;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  string S; cin >> S;

  int cnt = 0;
  while(!M[S]) {
    M[S] = true;

    string T = S;
    for(int i = 1; i < N - 1; i++) {
      if(S[i - 1] - '0' + S[i + 1] - '0' == 1) T[i] = '1';
      else T[i] = '0';
    }
    if(S[1] - '0' + S[N - 1] - '0' == 1) T[0] = '1';
    else T[0] = '0';

    if(S[0] - '0' + S[N - 2] - '0' == 1) T[N - 1] = '1';
    else T[N - 1] = '0';

    S = T;
    cout << S << endl;
    cnt++;
  }
  cout << cnt << endl;
}
