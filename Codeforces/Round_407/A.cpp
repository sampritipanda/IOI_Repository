#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long A[100001];
long long S1[100001];
long long S1_suff_max[100001];
long long S2[100001];
long long S2_suff_max[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 2; i <= N; i++) {
    S1[i] = S1[i - 1];
    if(i % 2 == 0) {
      S1[i] += abs(A[i] - A[i - 1]);
    }
    else {
      S1[i] -= abs(A[i] - A[i - 1]);
    }
  }
  S1_suff_max[N] = S1[N];
  for(int i = N - 1; i >= 1; i--) {
    S1_suff_max[i] = max(S1[i], S1_suff_max[i + 1]);
  }

  for(int i = 2; i <= N; i++) {
    S2[i] = S2[i - 1];
    if(i % 2 == 0) {
      S2[i] -= abs(A[i] - A[i - 1]);
    }
    else {
      S2[i] += abs(A[i] - A[i - 1]);
    }
  }
  S2_suff_max[N] = S2[N];
  for(int i = N - 1; i >= 1; i--) {
    S2_suff_max[i] = max(S2[i], S2_suff_max[i + 1]);
  }

  long long ans = LLONG_MIN/2;
  for(int i = 1; i < N; i += 2) {
    ans = max(ans, S1_suff_max[i + 1] - S1[i]);
  }

  for(int i = 2; i < N; i += 2) {
    ans = max(ans, S2_suff_max[i + 1] - S2[i]);
  }

  cout << ans << endl;
}
