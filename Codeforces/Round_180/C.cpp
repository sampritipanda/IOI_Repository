// Splitting the Uniqueness

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > S;
vector<int> A, B;

int main() {
  ios::sync_with_stdio(false);

  int N; cin >> N;
  S.resize(N);
  A.resize(N); B.resize(N);

  for(int i = 0; i < N; i++) {
    int s; cin >> s;
    S[i] = {s, i};
  }

  sort(S.begin(), S.end());

  int limit = ceil(N/3.0);
  int i = 0;

  for(; i < limit; i++) {
    A[S[i].second] = 0;
    B[S[i].second] = S[i].first;
  }

  for(; i < min(limit + limit, N); i++) {
    A[S[i].second] = S[i].first;
    B[S[i].second] = 0;
  }

  for(; i < N; i++) {
    A[S[i].second] = N - i - 1;
    B[S[i].second] = S[i].first - N + i + 1;
  }

  cout << "YES" << endl;
  for(int i = 0; i < N; i++) cout << A[i] << " "; cout << endl;
  for(int i = 0; i < N; i++) cout << B[i] << " "; cout << endl;
}
