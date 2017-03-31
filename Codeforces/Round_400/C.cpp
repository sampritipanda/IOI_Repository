#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

long long A[100001];
long long P[100001];
map<long long, int> cnt;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  A[0] = P[0] = 0;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    P[i] = P[i - 1] + A[i];
  }

  if(K == 1) {
    long long ans = 0;
    cnt[P[0]]++;
    for(int i = 1; i <= N; i++) {
      ans += cnt[P[i] - 1];
      cnt[P[i]]++;
    }
    cout << ans << endl;
  }
  else if(K == -1) {
    long long ans = 0;
    cnt[P[0]]++;
    for(int i = 1; i <= N; i++) {
      ans += cnt[P[i] - 1];
      ans += cnt[P[i] + 1];
      cnt[P[i]]++;
    }
    cout << ans << endl;
  }
  else {
    vector<long long> cands;
    long long limit = (long long)1e16;
    long long curr = 1;
    while(curr <= limit) {
      cands.push_back(curr);
      curr *= K;
    }
    cout << endl;

    long long ans = 0;
    cnt[P[0]]++;
    for(int i = 1; i <= N; i++) {
      for(long long x: cands) {
        ans += cnt[P[i] - x];
      }
      cnt[P[i]]++;
    }
    cout << ans << endl;
  }
}
