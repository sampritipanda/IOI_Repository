// Mega Inversions

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100001];
long long bit1[100001];
long long bit2[100001];

long long query(long long bit[], int i) {
  long long ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(long long bit[], int i, int val) {
  while(i <= N) {
    bit[i] += val;
    i += i & -i;
  }
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) bit1[i] = bit2[i] = 0;

  long long ans = 0;
  for(int i = N; i >= 1; i--) {
    ans += query(bit2, A[i] - 1);
    update(bit2, A[i], query(bit1, A[i] - 1));
    update(bit1, A[i], 1);
  }

  cout << ans << endl;
}
