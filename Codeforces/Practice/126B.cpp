#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int Z[1000000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S;
  int N = S.length();

  int L = 0, R = 0;
  for(int i = 1; i < N; i++) {
    if(i > R) {
      L = R = i;
      while(R < N && S[R - L] == S[R]) R++;
      R--;
      Z[i] = R - L + 1;
    }
    else {
      int k = i - L;
      if(Z[k] < R - i + 1) {
        Z[i] = Z[k];
      }
      else {
        L = i;
        while(R < N && S[R - L] == S[R]) R++;
        R--;
        Z[i] = R - L + 1;
      }
    }
  }

  int best = 0, pref_max = 0;
  for(int i = 2; i < N; i++) {
    pref_max = max(pref_max, Z[i - 1]);
    if(Z[i] == N - i && pref_max >= Z[i]) {
      best = max(best, Z[i]);
    }
  }

  if(best == 0) cout << "Just a legend" << endl;
  else {
    for(int i = 0; i < best; i++) cout << S[i];
    cout << endl;
  }
}
