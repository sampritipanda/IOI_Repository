#include <iostream>
#include <string>

using namespace std;

unsigned long long prefix_hashes[100000];
unsigned long long suffix_hashes[100000];
unsigned long long modexp_precalc[100010];
unsigned long long R = 101ULL;
unsigned long long M = 1000000007ULL;

unsigned long long prefix_hash(int i, int j) {
  if(i == 0) return prefix_hashes[j];
  unsigned long long ans = prefix_hashes[j] - ((modexp_precalc[j - i + 1] * prefix_hashes[i - 1]) % M);
  while(ans < 0) ans += M;
  return ans % M;
}

unsigned long long suffix_hash(int i, int j) {
  if(j == 0) return suffix_hashes[i];
  unsigned long long ans = suffix_hashes[i] - ((modexp_precalc[j - i + 1] * suffix_hashes[j + 1]) % M);
  while(ans < 0) ans += M;
  return ans % M;
}

int main() {
  ios::sync_with_stdio(false);

  string S; cin >> S;
  int N = S.length();

  modexp_precalc[0] = 1;
  for(int i = 1; i <= (N + 1); i++) modexp_precalc[i] = (modexp_precalc[i - 1] * R) % M;

  for(int i = 0; i < N; i++) {
    prefix_hashes[i] = ( (i > 0 ? prefix_hashes[i - 1] : 0) * R + (S[i] - 'a') ) % M;
  }

  for(int i = N - 1; i >= 0; i++) {
    suffix_hashes[i] = ( (i < (N - 1) ? suffix_hashes[i - 1] : 0) * R + (S[i] - 'a') ) % M;
  }

  int Q; cin >> Q;
  while(Q--) {
    int i, j, k, l; cin >> i >> j >> k >> l;

    if(j < k || i > l) {
      if((j - i + 1) & 1) {
        if(prefix_hash(i, (i + j)/2) == suffix_hash((i + j)/2, j)) {
          cout << "Yes" << '\n';
        }
        else {
          cout << "No" << '\n';
        }
      }
      else {
        if(prefix_hash(i, (i + j)/2) == suffix_hash((i + j)/2 + 1, j)) {
          cout << "Yes" << '\n';
        }
        else {
          cout << "No" << '\n';
        }
      }
    }
    else if(k <= i && j <= l) {
    }
  }
}
