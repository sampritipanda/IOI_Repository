#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > A;
long long M[100000], S[100000], prefix_S[100000];

inline long long prefix_sum(int i, int j) {
  if(i == 0) return prefix_S[j];
  else return prefix_S[j] - prefix_S[i - 1];
}

int main() {
  int N, D; cin >> N >> D;

  for(int i = 0; i < N; i++) {
    int m, s; cin >> m >> s;
    A.push_back({m, s});
  }

  sort(A.begin(), A.end());

  for(int i = 0; i < N; i++) {
    M[i] = A[i].first;
    S[i] = A[i].second;
  }

  prefix_S[0] = S[0];
  for(int i = 1; i < N; i++) {
    prefix_S[i] = prefix_S[i - 1] + S[i];
  }

  long long max_pos = 0;
  for(int i = 0; i < N; i++) {
    int j = (lower_bound(M, M + N, M[i] + D) - M) - 1;
    max_pos = max(max_pos, prefix_sum(i, j));
  }

  cout << max_pos << endl;
}
