#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int used[500001];  // used[i] = 0 if not done yet, length of the largest fish with gem i
int freq[500001];
int L[500001], F[500001];
vector<int> by_freq[500001];
int segtree[2000001][2];  // 0 = not-used product, 1 = used product
vector<pair<int, int> > longest; int long_rev[500001];
int M;

void update(int L, int R, int i, int x, int v, int t) {
  if(L == R) {
    segtree[i][t] = v % M;
    segtree[i][t ^ 1] = 1 % M;
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(L, mid, 2*i + 1, x, v, t);
  }
  else {
    update(mid + 1, R, 2*i + 2, x, v, t);
  }

  segtree[i][0] = (segtree[2*i + 1][0] * segtree[2*i + 2][0]) % M;
  segtree[i][1] = (segtree[2*i + 1][1] * segtree[2*i + 2][1]) % M;
}

int query(int L, int R, int i, int qL, int qR, int t) {
  if(L > qR || R < qL) return 1;
  if(qL <= L && R <= qR) return segtree[i][t];

  int mid = (L + R)/2;
  return (query(L, mid, 2*i + 1, qL, qR, t) * query(mid + 1, R, 2*i + 2, qL, qR, t)) % M;
}

// counts number of fish with gem f and length <= l
int count(int f, int l) {
  return upper_bound(by_freq[f].begin(), by_freq[f].end(), l) - by_freq[f].begin();
}

int main() {
  int N, K; cin >> N >> K >> M;

  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());
  for(int i = 0; i < N; i++) {
    L[i] = A[i].first;
    F[i] = A[i].second;
    by_freq[F[i]].push_back(L[i]);
  }

  longest.push_back({0, 0});
  for(int i = 1; i <= K; i++) {
    longest.push_back({by_freq[i].back(), i});
  }
  sort(longest.begin(), longest.end());
  for(int i = 1; i <= K; i++) {
    long_rev[longest[i].second] = i;
  }

  for(int i = 0; i < 4 * N; i++) {
    segtree[i][0] = segtree[i][1] = 1;
  }

  for(int i = 0; i < N; i++) freq[F[i]]++;
  for(int i = 1; i <= K; i++) {
    update(1, K, 0, long_rev[i], freq[i] + 1, 0);
  }
  int ptr = N - 1;

  int ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(used[F[i]]) continue;

    while(ptr >= 0 && L[ptr] > L[i]/2) {
      freq[F[ptr]]--;
      update(1, K, 0, long_rev[F[ptr]], freq[F[ptr]] + 1, (used[F[ptr]] ? 1 : 0));
      ptr--;
    }

    int pure = segtree[0][0];
    update(1, K, 0, long_rev[F[i]], 1, 0);
    int pure_without_curr = segtree[0][0];
    update(1, K, 0, long_rev[F[i]], freq[F[i]] + 1, 0);
    ans = (ans + pure) % M;

    int qL = upper_bound(longest.begin(), longest.end(), make_pair(L[i], F[i])) - longest.end();
    int nth_curr_el = by_freq[F[i]][freq[F[i]]];
    int qR_1 = lower_bound(longest.begin(), longest.end(), make_pair(nth_curr_el * 2, 0)) - longest.begin() - 1;
    int qR_2 = lower_bound(longest.begin(), longest.end(), make_pair(L[i] * 2, 0)) - longest.begin() - 1;
    int mixed = query(1, K, 0, qL, min(qR_1, qR_2), 1);
    mixed = (mixed - 1 + M) % M;
    mixed = (mixed * pure_without_curr) % M;

    ans = (ans + mixed) % M;
    used[F[i]] = L[i];
    update(1, K, 0, long_rev[F[i]], freq[F[i]] + 1, 1);
  }
  cout << ans << endl;
}

