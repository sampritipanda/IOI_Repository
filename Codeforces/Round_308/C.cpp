// Vanya and Scales

#include <iostream>
#include <algorithm>

using namespace std;

long long mypow(int base, int exp) {
  long long result = 1;
  while(exp > 0) {
    if(exp & 1) result *= base;
    base = base * base;
    exp >>= 1;
  }
  return result;
}

int powers[101];

int step = 0;

bool solve(int W, int M, int exp, int L, int R) {
  if(exp > 100) return false;

  long long curr_power = powers[exp];
  if(L == curr_power + R || L + R == curr_power) return true;
  else if(L + R < curr_power || curr_power > M) return false;
  else {
    bool no_change = solve(W, M, exp + 1, L, R);
    bool left_add = solve(W, M, exp + 1, L + curr_power, R);
    bool right_add = solve(W, M, exp + 1, L, R + curr_power);

    return no_change || left_add || right_add;
  }
}

int main() {
  int W, M; cin >> W >> M;
  powers[0] = 1;
  for(int i = 1; i <= 100; i++) powers[i] = powers[i - 1] * W;

  if(M == 1 || W == 2) cout << "YES" << endl;
  else if(solve(W, M, 0, M, 0)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
