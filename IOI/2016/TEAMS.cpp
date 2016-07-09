#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// A => Sorted by min, B => Sorted by max
vector<pair<int, int> > A, B;
int K[200000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  A.resize(N); B.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    B[i] = A[i];
  }

  sort(A.begin(), A.end());

  int Q; cin >> Q;

  while(Q--) {
    int M; cin >> M;
    for(int i = 0; i < M; i++) cin >> K[i];
    long long sum = 0;
    for(int i = 0; i < M; i++) sum += K[i];
    if(sum > N) {
      cout << 0 << endl;
      continue;
    }

    sort(K, K + M);

    bool pos = true;

    int i = 0, j = 0;
    while(i < M) {
      int curr = K[i];
      while(curr > 0 && j < M) {
        if(A[j].first <= K[i] && K[i] <= A[j].second) {
          curr--;
        }
        j++;
      }
      if(curr > 0) {
        pos = false;
        break;
      }
      i++;
    }

    if(pos) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
