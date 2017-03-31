#include <iostream>
#include <algorithm>

using namespace std;

int A[2500];
int B[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> A[i];
    B[A[i]] = 1;
  }
  sort(A, A + N);

  int ans = 1;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      int d = A[j] - A[i];
      int curr = 2;
      for(int k = A[j] + d; k <= 100000 && B[k]; k += d) curr++;
      ans = max(ans, curr);
    }
  }
  cout << ans << endl;
}
