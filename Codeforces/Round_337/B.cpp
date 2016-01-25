#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int A[200001];
int P[200001], S[200001];
map<int, vector<int> > I;

int main() {
  long long N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> A[i];

  P[1] = A[1]; for(int i = 2; i <= N; i++) P[i] = min(P[i - 1], A[i]);
  S[N] = A[N]; for(int i = N - 1; i >= 1; i--) S[i] = min(S[i + 1], A[i]);

  for(int i = 1; i <= N; i++) I[A[i]].push_back(i);

  long long ans = 0;
  for(int start = 1; start <= N + 1; start++) {
    long long curr = 0;

    curr += N - start + 1;

    int M = P[N];
    auto end_it = lower_bound(I[M].begin(), I[M].end(), start);

    if(end_it == I[M].end()) {
      curr += M * ((long long)N);
      curr += *I[M].begin() - 1;
    }
    else {
      curr += (M - 1) * ((long long)N);
      curr += *end_it - 1;
    }

    ans = max(ans, curr);
  }

  cout << ans << endl;
}
