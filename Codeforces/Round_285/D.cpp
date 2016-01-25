#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int bit[200001];
int A[200002];
int B[200002];
int C[200002];
int N;

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int v) {
  while(i <= N) {
    bit[i] += v;
    i += i & -i;
  }
}

int main() {
  cin >> N;

  memset(bit, 0, sizeof bit);

  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = N - 1; i >= 0; i--) {
    int x = A[i] + 1;
    A[i] = query(x - 1);
    update(x, 1);
  }

  memset(bit, 0, sizeof bit);

  for(int i = 0; i < N; i++) cin >> B[i];
  for(int i = N - 1; i >= 0; i--) {
    int x = B[i] + 1;
    B[i] = query(x - 1);
    update(x, 1);
  }

  reverse(A, A + N);
  reverse(B, B + N);

  for(int i = 0; i < N; i++) {
    C[i] += A[i] + B[i];
    C[i + 1] += C[i]/(i + 1);
    C[i] %= (i + 1);
  }

  vector<int> ans;
  memset(bit, 0, sizeof bit);
  for(int i = 1; i <= N; i++) update(i, 1);

  for(int i = N - 1; i >= 0; i--) {
    int L = 1, R = N;
    while(L < R) {
      int mid = (L + R) >> 1;
      if(query(mid) >= C[i] + 1) R = mid;
      else L = mid + 1;
    }
    ans.push_back(L - 1);
    update(L, -1);
  }

  for(auto it: ans) cout << it << " "; cout << endl;
}
