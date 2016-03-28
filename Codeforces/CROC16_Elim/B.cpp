#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];
int bit[100001];

long long query(int i) {
  long long ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int v) {
  while(i <= 100000) {
    bit[i] += v;
    i += i & -i;
  }
}

int main() {
  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) A[i] = i;

  for(int i = 1; i <= min(K, N/2); i++) {
    swap(A[i], A[N - i + 1]);
  }

  // for(int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;

  long long ans = 0;
  for(int i = N; i >= 1; i--) {
    ans += query(A[i] - 1);
    update(A[i], 1);
  }
  cout << ans << endl;
}
