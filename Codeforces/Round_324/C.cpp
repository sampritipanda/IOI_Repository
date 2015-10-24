#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int N, T; cin >> N >> T;
  string A, B; cin >> A >> B;
  vector<bool> u_A(N, false), u_B(N, false);
  int S = N - T;

  if(S == N) {
    if(A == B) cout << A << endl;
    else cout << -1 << endl;
  }
  else {
    int x = 0, y = 0;
    for(int i = 0; i < N; i++) {
      if(x == y && x == S) break;
      if(A[i] == B[i]) {
        x++; y++;
        u_A[i] = u_B[i] = true;
      }
    }

    if(!(x == y && x == S)) {
      for(int i = 0; i < N; i++) {
        if(x == y && x == S) break;
        if(u_A[i] || u_B[i]) continue;

        if(x < y) u_A[i] = true, x++;
        else if(y < x) u_B[i] = true, y++;
        else u_A[i] = true, x++;
      }
    }

    if(x == y && x == S) {
      for(int i = 0; i < N; i++) {
        if(u_A[i]) cout << A[i];
        else if(u_B[i]) cout << B[i];
        else {
          if(A[i] != 'a' && B[i] != 'a') cout << 'a';
          else if(A[i] != 'b' && B[i] != 'b') cout << 'b';
          else cout << 'c';
        }
      }
      cout << endl;
    }
    else cout << -1 << endl;
  }
}
