#include <iostream>
#include <algorithm>

using namespace std;

string S;
int A[100001];
int B[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  cin >> S;

  for(int i = 1; i <= N; i++) {
    A[i] = A[i - 1];
    B[i] = B[i - 1];

    if(S[i - 1] == 'a') A[i]++;
    else B[i]++;
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    ans = max(ans, (int)(upper_bound(A + 1, A + 1 + N, A[i - 1] + K) - (A + i)));
    ans = max(ans, (int)(upper_bound(B + 1, B + 1 + N, B[i - 1] + K) - (B + i)));
  }

  cout << ans << endl;
}
