#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, B;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;
  while(T--) {
    int N, K; cin >> N >> K;

    A.resize(N); B.resize(N);

    for(int i = 0; i < N; i++) cin >> A[i];

    int k = 1;
    for(; k <= K; k++) {
      B[0] = A[0] & A[1] & A[N - 1];
      for(int i = 1; i < N - 1; i++) B[i] = A[i - 1] & A[i] & A[i + 1];
      B[N - 1] = A[N - 2] & A[N - 1] & A[0];

      if(A == B) break;
      A = B;
    }

    for(auto it: B) cout << it << " ";
    cout << endl;

    cout << k << endl;
  }
}
