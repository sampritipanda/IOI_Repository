#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool solve(long long R, long long C, long long M, long long K, long long J) {
  if(M + K + J != R * C) return false;

  if(M % R == 0 && K % R == 0 && J % R == 0) return true;
  if(M % C == 0 && K % C == 0 && J % C == 0) return true;

  if(M % R == 0) {
    long long C2 = C - M/R;
    if(K % C2 == 0 && J % C2 == 0) return true;
  }
  if(K % R == 0) {
    long long C2 = C - K/R;
    if(M % C2 == 0 && J % C2 == 0) return true;
  }
  if(J % R == 0) {
    long long C2 = C - J/R;
    if(K % C2 == 0 && M % C2 == 0) return true;
  }

  if(M % C == 0) {
    long long R2 = R - M/C;
    if(K % R2 == 0 && J % R2 == 0) return true;
  }
  if(K % C == 0) {
    long long R2 = R - K/C;
    if(M % R2 == 0 && J % R2 == 0) return true;
  }
  if(J % C == 0) {
    long long R2 = R - J/C;
    if(K % R2 == 0 && M % R2 == 0) return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long R, C, M, K, J; cin >> R >> C >> M >> K >> J;

    if(solve(R, C, M, K, J)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
