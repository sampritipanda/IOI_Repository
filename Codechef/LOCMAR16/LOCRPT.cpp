#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

long long R = 101LL;
long long M = 1000000007LL;

long long pre_hash[1004];
long long modexp_precalc[1004];
char temp[1004];
char A[1004];
int N;

long long prefix_hash(int i, int j) {
  long long ans = pre_hash[j] - ((modexp_precalc[j - i + 1] * pre_hash[i - 1]) % M);
  while(ans < 0) ans += M;
  return ans % M;
}

bool check(int L) {
  set<long long> done;
  for(int i = (N + 1) - L; i >= 1; i--) {
    if(i + L <= (N + 1) - L) done.insert(prefix_hash(i + L, i + L + L - 1));

    long long curr_hash = prefix_hash(i, i + L - 1);
    if(done.count(curr_hash) > 0) return true;
  }
  return false;
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);
    scanf(" %s", temp);

    for(int i = 1; i <= N; i++) A[i] = temp[i - 1];

    modexp_precalc[0] = 1;
    for(int i = 1; i <= (N + 1); i++) modexp_precalc[i] = (modexp_precalc[i - 1] * R) % M;

    pre_hash[0] = 0;
    for(int i = 1; i <= N; i++) {
      pre_hash[i] = (pre_hash[i - 1] * R + A[i]) % M;
    }

    int L = 0, R = N;
    while(L < R) {
      int mid = (L + R + 1)/2;
      if(check(mid)) L = mid;
      else R = mid - 1;
    }

    printf("%d\n", L);
  }
}

