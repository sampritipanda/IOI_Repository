// Anton and currency you all know

#include <iostream>
#include <string>

using namespace std;

string solve(string S, int N) {
  for(int i = 0; i < N; i++) {
    if((S[i] - '0') % 2 == 0 && S[N - 1] > S[i]) {
      swap(S[i], S[N - 1]);
      return S;
    }
  }

  for(int i = 0; i < N; i++) {
    if((S[i] - '0') % 2 == 0 && S[i] == S[N - 1]) {
      swap(S[i], S[N - 1]);
      return S;
    }
  }

  for(int i = N - 2; i >= 0; i--) {
    if((S[i] - '0') % 2 == 0) {
      swap(S[i], S[N - 1]);
      return S;
    }
  }

  return "-1";
}

int main() {
  string N; cin >> N;

  cout << solve(N, N.length()) << endl;
}
