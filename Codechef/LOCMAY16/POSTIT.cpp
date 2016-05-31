#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

string S;
long long N, K, M;
long long F[26], F2[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S;
  N = S.length();
  cin >> K >> M;

  for(char c: S) {
    F[c - 'a']++;
  }

  long long L = 1, R = N * K;
  while(L <= R) {
    long long mid = (L + R)/2;
    long long sum = 0;
    for(int i = 0; i < 26; i++) {
      if(F[i] == 0) continue;
      long long L2 = 1, R2 = M;
      while(L2 <= R2) {
        long long mid2 = (L2 + R2)/2;
        long long curr = (F[i] * K + mid2 - 1)/mid2;
        if(curr <= mid) {
          if(L2 == R2) break;
          R2 = mid2;
        }
        else {
          L2 = mid2 + 1;
        }
      }
      sum += L2;
    }
    if(sum <= M) {
      if(L == R) break;
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }

  if(L <= N * K) {
    long long ans = L;
    cout << ans << endl;

    for(int i = 0; i < 26; i++) {
      F2[i] = F[i];
    }
    long long left = M;
    for(int i = 25; i >= 0; i--) {
      if(F[i] == 0) continue;
      long long L = 1, R = M;
      while(L < R) {
        long long mid = (L + R)/2;
        long long curr = (F[i] * K + mid - 1)/mid;
        if(curr <= ans) {
          R = mid;
        }
        else {
          L = mid + 1;
        }
      }
      left -= L;
      F2[i] = L;
    }
    F2[0] += left;
    for(int i = 0; i < 26; i++) {
      for(long long j = 0; j < F2[i]; j++) cout << char('a' + i);
    }
    cout << endl;
  }
  else cout << -1 << endl;
}
