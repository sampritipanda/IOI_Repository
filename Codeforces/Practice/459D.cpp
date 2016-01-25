#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int A[1000000];
int X[1000000];
int Y[1000000];
int bit[1000000];
map<int, int> M;

int N;

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int val) {
  while(i <= N) {
    bit[i] += val;
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    M[A[i]]++;
    X[i] = M[A[i]];
  }

  M.clear();
  for(int j = N - 1; j >= 0; j--) {
    M[A[j]]++;
    Y[j] = M[A[j]];
  }

  long long ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    ans += query(X[i] - 1);
    update(Y[i], 1);
  }

  cout << ans << endl;
}
