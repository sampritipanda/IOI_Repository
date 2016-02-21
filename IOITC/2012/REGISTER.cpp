#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[100001];
int bit[100001];
int P[100001];   // P[i] = index of A[i] in sorted array
int P2[100001];  // P2[i] = index of S[i] in A[i]
vector<pair<int, int> > temp;

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= (i & -i);
  }
  return ans;
}

void update(int i, int val) {
  while(i <= 100000) {
    bit[i] += val;
    i += (i & -i);
  }
}

int upper_bound(int x) {
  int L = 1, R = N + 1;

  while(L < R) {
    int mid = (L + R)/2;

    if(query(mid) > x) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }

  return L;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int Q;
  scanf("%d %d", &N, &Q);

  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    temp.push_back({x, i});
  }
  sort(temp.begin(), temp.end());

  for(int j = 1; j <= N; j++) {
    int x = temp[j - 1].first, i = temp[j - 1].second;
    A[j] = x;
    P[i] = j;
    P2[j] = i;
  }

  for(int i = 1; i <= N; i++) update(i, A[i] - A[i - 1]);

  while(Q--) {
    int t, x; scanf("%d %d", &t, &x);

    if(t == 1) {
      x++;
      int ind = P[x];
      int val = query(ind);
      int ind2 = upper_bound(val) - 1;
      int opp = x, opp2 = P2[ind2];
      update(ind2, 1); update(ind2 + 1, -1);

      swap(P[x], P[opp2]);
      P2[ind] = opp2; P2[ind2] = x;
    }
    else if(t == 2) {
      printf("%d\n", N - upper_bound(x - 1) + 1);
    }
    else {
      int ind = upper_bound(x - 1);
      update(ind, -1);
    }
  }
}
