#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long P[500001];
string S;
long long A[500001], B[500001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> P[i];
  cin >> S;

  for(int i = 1; i <= N; i++) {
    A[i] = A[i - 1]; B[i] = B[i - 1];

    if(S[i - 1] == 'A') A[i] += P[i];
    else B[i] += P[i];
  }

  long long ans = B[N];
  for(int i = 1; i <= N; i++) {
    ans = max(ans, B[N] - B[i] + A[i]);
  }

  for(int i = N; i >= 1; i--) {
    ans = max(ans, B[N] - (B[N] - B[i - 1]) + (A[N] - A[i - 1]));
  }

  cout << ans << endl;
}

