#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[51];
int B[51];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int sum = 0;
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      sum += A[i];
    }

    int x = (N * (N - 1))/2;
    if((sum - x) < 0 || (sum - x) % N != 0) cout << -1 << endl;
    else {
      int a = (sum - x)/N;
      for(int i = 0; i < N; i++) {
        B[i + 1] = a + i;
      }

      int cnt = 0;
      while(true) {
        bool pos = true;
        for(int i = 1; i < N; i++) {
          if(A[i] + 1 != A[i + 1]) {
            pos = false; break;
          }
        }

        if(pos) break;

        bool done = false;
        for(int i = 1; i <= N; i++) {
          if(A[i] - B[i] < 0) {
            for(int j = 1; j <= N; j++) {
              if(A[j] - B[j] > 0) {
                int k = min(A[j] - B[j], B[i] - A[i]);
                A[j] -= k;
                A[i] += k;
                cnt += k;
              }
            }
          }
        }
      }

      cout << cnt << endl;
    }
  }
}
