// Maximize Disjoint Pair Sum

#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];
bool check[100000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, D; cin >> N >> D;

    for(int i = 0; i < N; i++) {
      cin >> A[i];
      check[i] = false;
    }

    sort(A, A + N);

    long long ans = 0;
    for(int i = N - 2; i >= 0; i--) {
      if(check[i + 1] || A[i + 1] - A[i] >= D) continue;

      check[i] = check[i + 1] = true;
      ans += A[i];
      ans += A[i + 1];
    }

    cout << ans << endl;
  }
}
