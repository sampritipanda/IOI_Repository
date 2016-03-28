#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

long long A[1000000];
long long B[1000000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  double ans = 0;
  double num = 0, den = 0;
  for(int i = 0; i < N; i++) {
    ans = max(ans, double(A[i])/B[i]);
  }

  cout << fixed << setprecision(8) << ans << endl;
}
