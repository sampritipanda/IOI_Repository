#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int A[200001];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    int f; cin >> f;
    A[f] = i;
  }

  long long ans = 0;
  for(int i = 2; i <= N; i++) ans += abs(A[i] - A[i - 1]);
  cout << ans << endl;
}
