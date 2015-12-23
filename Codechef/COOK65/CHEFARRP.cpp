#include <iostream>
#include <algorithm>

using namespace std;

int A[51];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 1; i <= N; i++) cin >> A[i];

    int ans = 0;

    for(int i = 1; i <= N; i++) {
      for(int j = i; j <= N; j++) {
        long long sum = 0, prod = 1;
        for(int k = i; k <= j; k++) {
          sum += A[k];
          prod *= A[k];
        }

        if(sum == prod) ans++;
      }
    }

    cout << ans << endl;
  }
}
