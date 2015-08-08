// Way Out

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long A[1000001];
long long sum[1000004];
int N, H;

inline long long prefix_sum(int L, int R) {
  if(L == 0) return A[R];
  else return A[R] - A[L - 1];
}

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    cin >> N >> H;

    for(int i = 0; i <= N; i++) A[i] = sum[i] = 0;

    for(int i = 0; i < N; i++) {
      int l, h; cin >> l >> h;
      sum[l]++;
      sum[h + 1]--;
    }

    for(int i = 1; i < N; i++) sum[i] += sum[i - 1];

    A[0] = N - sum[0];
    for(int i = 0; i < N; i++) {
      A[i] = N - sum[i];
    }

    for(int i = 1; i < N; i++) A[i] += A[i - 1];

    long long min_cost = LLONG_MAX;
    for(int i = 0; i < N - H + 1; i++) {
      min_cost = min(min_cost, prefix_sum(i, i + H - 1));
    }

    cout << min_cost << endl;
  }
}
