#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C[100000];
int A[100000];  // Answer if i chosen
int B[100000];  // Answer if i not chosen
int H[100000], P[100000];
int N;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> C[i];

  for(int i = 1; i < N; i++) {
    cin >> H[i] >> P[i];
  }

  for(int i = 0; i < N; i++) A[i] = C[i];

  for(int i = N - 1; i >= 1; i--) {
    int a1 = A[H[i]], b1 = B[H[i]];
    int a2 = A[i], b2 = B[i];

    if(P[i] == 0) {
      A[H[i]] = a1 + b2;
      B[H[i]] = max(b1 + a2, b1 + b2);
    }
    else if(P[i] == 1) {
      A[H[i]] = max({a1 + a2, a1 + b2, b1 + a2});
      B[H[i]] = b1 + b2;
    }
    else {
      A[H[i]] = max(a1 + b2, b1 + a2);
      B[H[i]] = b1 + b2;
    }
  }

  cout << max(A[0], B[0]) << endl;
}
