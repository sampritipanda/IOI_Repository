#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

long long A[100001];
long long P[100001];
int N;

long long sum(int L, int R) {
  return P[R] - P[L - 1];
}

long long count(long long X) {
  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += (P + N + 1) - lower_bound(P + 1, P + N + 1, P[i - 1] + X);
  }
  return ans;
}

vector<long long> ans;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int K; cin >> N >> K;
  int orig_K = K;

  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];

  long long L = 1, R = 10000000000000000LL;
  while(L < R) {
    long long mid = (L + R + 1)/2;
    if(count(mid) < K) {
      R = mid - 1;
    }
    else {
      L = mid;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = N; j >= i; j--) {
      if(sum(i, j) >= L) {
        ans.push_back(sum(i, j));
        K--;
      }
      else break;

      if(K == 0) break;
    }
    if(K == 0) break;
  }

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  assert(ans.size() == orig_K);

  for(auto it: ans) cout << it << " "; cout << endl;
}

