#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;

int A[MAX_N + 1];
map<int, int> compres;
vector<long long> dp1, dp2;

long long query(vector<long long>& bit, int i) {
  long long ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(vector<long long>& bit, int i, long long val) {
  while(i <= MAX_N) {
    bit[i] += val;
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    compres[A[i]] = 0;
  }

  int count = 0;
  for(auto it: compres) {
    compres[it.first] = ++count;
  }

  for(int i = 1; i <= N; i++) {
    A[i] = compres[A[i]];
  }

  dp1.resize(MAX_N + 1);
  dp2.resize(MAX_N + 1);

  long long ans = 0;
  for(int i = N; i >= 1; i--) {
    long long a = query(dp1, A[i] - 1);
    long long b = query(dp2, A[i] - 1);
    ans += b;

    update(dp1, A[i], 1);
    update(dp2, A[i], a);
  }

  cout << ans << endl;
}
