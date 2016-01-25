#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> X, Y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  X.resize(N + 1); Y.resize(N + 1);

  for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  long long ans = 0;
  long long sq_sum = X[0] * X[0], sum = X[0];
  for(int i = 1; i < N; i++) {
    ans += i * X[i] * X[i] + sq_sum - 2 * X[i] * sum;
    sum += X[i];
    sq_sum += X[i] * X[i];
  }

  sq_sum = Y[0] * Y[0], sum = Y[0];
  for(int i = 1; i < N; i++) {
    ans += i * Y[i] * Y[i] + sq_sum - 2 * Y[i] * sum;
    sum += Y[i];
    sq_sum += Y[i] * Y[i];
  }

  cout << ans << endl;
}
