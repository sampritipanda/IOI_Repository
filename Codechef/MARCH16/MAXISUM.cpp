#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<long long, long long> > A;
long long C[100000];

long long max_inc(long long A, long long B, long long K) {
  long long orig = A * B;
  if(A > B) swap(A, B);
  long long diff = B - A;
  A += min(K, diff);
  K -= min(K, diff);

  A += K/2; B += K/2;
  A += K % 2;
  return A * B - orig;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    A.clear();

    int N; long long K; cin >> N >> K;

    A.resize(N);

    for(int i = 0; i < N; i++) cin >> A[i].first;
    for(int i = 0; i < N; i++) cin >> A[i].second;

    for(int i = 0; i < N; i++) {
      if(A[i].first <= 0 && A[i].second <= 0) {
        A[i].first = -A[i].first;
        A[i].second = -A[i].second;
      }
    }

    for(int i = 0; i < N; i++) C[i] = A[i].first * A[i].second;

    long long max_change = 0;
    for(int i = 0; i < N; i++) {
      long long orig = A[i].first * A[i].second;
      long long new1 = (A[i].first + K) * A[i].second;
      long long new2 = (A[i].first - K) * A[i].second;

      max_change = max(max_change, new1 - orig);
      max_change = max(max_change, new2 - orig);
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
      ans += C[i];
    }
    ans += max_change;

    cout << ans << endl;
  }
}
