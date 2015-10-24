#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long R = 101LL;
long long M = 1000000007LL;

long long pre_hash[100002];
long long suff_hash[100002];
long long modexp_precalc[100001];
char A[100001];

long long prefix_hash(int i, int j) {
  long long ans = pre_hash[j] - ((modexp_precalc[j - i + 1] * pre_hash[i - 1]) % M);
  while(ans < 0) ans += M;
  return ans % M;
}

long long suffix_hash(int i, int j) {
  long long ans = suff_hash[i] - ((modexp_precalc[j - i + 1] * suff_hash[j + 1]) % M);
  while(ans < 0) ans += M;
  return ans % M;
}

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();

    if(N == 1) {
      cout << 2 << endl;
      continue;
    }

    for(int i = 1; i <= N; i++) A[i] = S[i - 1];

    modexp_precalc[0] = 1;
    for(int i = 1; i <= (N + 1); i++) modexp_precalc[i] = (modexp_precalc[i - 1] * R) % M;

    pre_hash[0] = 0;
    for(int i = 1; i <= N; i++) {
      pre_hash[i] = (pre_hash[i - 1] * R + A[i]) % M;
    }

    suff_hash[N + 1] = 0;
    for(int i = N; i >= 1; i--) {
      suff_hash[i] = (suff_hash[i + 1] * R + A[i]) % M;
    }

    int count = 0;

    if(N % 2 == 0) {
      if(prefix_hash(1, N/2) == suffix_hash(N/2, N - 1)) count++;
      if(prefix_hash(2, N/2 + 1) == suffix_hash(N/2 + 1, N)) count++;

      for(int i = 2; i <= N/2 + 1; i++) {
        bool possible = true;
        if(!(prefix_hash(1, i - 1) == suffix_hash(N - i + 2, N))) possible = false;
        if(i < N/2 + 1) if(!(prefix_hash(i, N/2) == suffix_hash(N/2, N - i))) possible = false;
        if(possible) count++;
      }

      for(int i = N/2 + 2; i <= N; i++) {
        bool possible = true;
        if(!(prefix_hash(1, N - i + 1) == suffix_hash(i, N))) possible = false;
        if(!(prefix_hash(N + 2 - i + 1, N/2 + 1) == suffix_hash(N/2 + 1, i - 1))) possible = false;
        if(possible) count++;
      }
    }
    else {
      if(prefix_hash(1, N/2) == suffix_hash(N/2 + 1, N - 1)) count++;
      if(prefix_hash(2, N/2 + 1) == suffix_hash(N/2 + 2, N)) count++;

      for(int i = 2; i <= N/2; i++) {
        bool possible = true;
        if(!(prefix_hash(1, i - 1) == suffix_hash(N - i + 2, N))) possible = false;
        if(!(prefix_hash(i, N/2) == suffix_hash(N/2 + 1, N - i))) possible = false;
        if(possible) count++;
      }

      if(prefix_hash(1, N/2) == suffix_hash(N/2 + 2, N)) count += 2;

      for(int i = N/2 + 3; i <= N; i++) {
        bool possible = true;
        if(!(prefix_hash(1, N + 1 - i) == suffix_hash(i, N))) possible = false;
        if(!(prefix_hash(N + 2 - i + 1, N/2 + 1) == suffix_hash(N/2 + 2, i - 1))) possible = false;
        if(possible) count++;
      }
    }

    cout << count << endl;
  }
}
