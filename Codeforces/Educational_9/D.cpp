#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int A[1000001];
vector<int> I[1000001];
bool sieve[1000001];
int fact[1000001];

vector<int> P;
map<int, int> P_map;
int cnt;

void solve(int i, int val) {
  if(i == P.size()) {
    cnt += I[val].size();
    return;
  }

  int freq = P_map[P[i]];
  for(int j = 0; j <= freq; j++) {
    solve(i + 1, val);
    val *= P[i];
  }
}

int main() {
  for(int i = 2; i <= 1000000; i++) sieve[i] = true;
  for(int i = 2; i <= 1000000; i++) {
    if(!sieve[i]) continue;

    for(int j = i + i; j <= 1000000; j += i) {
      sieve[j] = false;
      fact[j] = i;
    }
  }

  sieve[1] = true;

  int N, M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    if(A[i] <= M) I[A[i]].push_back(i);
  }

  int L = 1, len = 0;
  for(int i = 1; i <= M; i++) {
    P.clear(); P_map.clear();
    int x = i;
    while(!sieve[x]) {
      P.push_back(fact[x]);
      ++P_map[fact[x]];
      x /= fact[x];
    }
    P.push_back(x);
    if(x > 1) ++P_map[x];

    P.resize(unique(P.begin(), P.end()) - P.begin());
    cnt = 0;
    solve(0, 1);

    if(cnt > len) {
      L = i;
      len = cnt;
    }
  }

  printf("%d %d\n", L, len);
  for(int i = 1; i <= N; i++) {
    if(L % A[i] == 0) printf("%d ", i);
  }
  printf("\n");
}
