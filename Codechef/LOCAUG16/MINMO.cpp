#include <iostream>
#include <algorithm>

using namespace std;

int X[100000];
int Y[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, B; cin >> N >> B;

  for(int i = 0; i < B; i++) cin >> X[i];
  for(int i = 0; i < B; i++) cin >> Y[i];

  long long ans = 0;

  for(int i = 0; i < B; i++) {
    ans += min({X[i] - 1 + Y[i] - 1, X[i] - 1 + N - Y[i], N - X[i] + Y[i] - 1, N - X[i] + N - Y[i]});
  }

  cout << ans << endl;
}
